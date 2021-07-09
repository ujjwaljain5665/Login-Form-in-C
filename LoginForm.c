#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#define ESC 27

void signup(void);
void login(void);

struct{
    char username[20];
    char password[20];
}s,s1;
COORD c={0,0};
void gotoxy(int x,int y){
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
FILE *fp;

void main(){
    int ch;
    while(1){
        system("cls");
        system("color 70");
        gotoxy(34,10);
        printf("***********************************");
        gotoxy(39,13);
        printf("Welcome To The Login Form");
        gotoxy(42,15);
        printf("Press 1 for Login\n");
        gotoxy(42,16);
        printf("Press 2 for Signup\n");
        gotoxy(42,17);
        printf("Press ESC to exit\n");
        gotoxy(34,19);
        printf("***********************************");
        gotoxy(40,21);
        printf("Enter Your Choice:");
        ch=getch();
        switch(ch){
            case '1':
                system("cls");
                gotoxy(38,16);
                printf("Loading:");
                for(int i=0;i<40;i++){
                    printf("%c",220);
                    Sleep(20);
                }
                login();
                break;
            case '2':
                system("cls");
                gotoxy(38,16);
                printf("Loading:");
                for(int i=0;i<40;i++){
                    printf("%c",220);
                    Sleep(20);
                }
                signup();
                break;
            case ESC:
                system("cls");
                system("color 04");
                gotoxy(44,15);
                printf("Exited!!!");
                exit(0);
        }
    }
    getch();
}

//Login Function.
void login(){
    int c;
    char username[20];
    char password[20];
    char chku;
    char chkp;
    system("cls");
    system("color 36");
    gotoxy(38,14);
    printf("------------------------------");
    gotoxy(38,22);
    printf("------------------------------");
    gotoxy(47,16);
    printf("Login Zone");
    fp=fopen("record.bin","rb");
    if(fp==NULL){
        gotoxy(46,16);
        printf("Error...File Doesn't Exist...!!!");
    }
    else{
        gotoxy(40,18);
        printf("Enter your username:");
        gets(username);
        gotoxy(40,19);
        printf("Enter Password:");
        int i;
        for(i=0;c=getch()!=13;i++){
            password[i]=c;
            printf("*");
        }
        password[i]='\0';
        while(!feof(fp)){
            if(fread(&s,sizeof(s),1,fp)==1){
                chku=strcmp(username,s.username);
                chkp=strcmp(password,s.password);
                if(chku==0 && chkp==0){
                    system("cls");
                    gotoxy(40,18);
                    printf("Hello %s , Have A Good Day.",username);
                    gotoxy(40,19);
                    printf("Press Any key To Continue.");
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                system("cls");
                gotoxy(30,10);
                printf("Invalid Login...!!!.Press any key to continue.");
            }
        }
    }
    getch();
}
void signup(){
    char c,choice;
    fp=fopen("record.bin","r");
    system("cls");
    system("color 8f");
    gotoxy(38,14);
    printf("------------------------------");
    gotoxy(38,22);
    printf("------------------------------");
    gotoxy(47,16);
    printf("Signup Zone");
    gotoxy(40,18);
    printf("Set Username:");
    gets(s.username);
    while(fread(&s1,sizeof(s1),1,fp)!=0){
        if(strcmp(s1.username,s.username)==0){
            system("cls");
            gotoxy(35,17);
            printf("Username already Exist...Try Again.");
            getch();
            fclose(fp);
            return;
        }
    }
    gotoxy(40,19);
    printf("Set Password:");
    for(int i=0;c=getche()!=13;i++){
        s.password[i]=c;
    } 
    gotoxy(41,21);
    printf("Are You Sure (Y/N):");
    choice=getch();
    fp=fopen("record.bin","ab");
    if(choice=='Y'||choice=='y'){
        fwrite(&s,sizeof(s),1,fp);
        system("cls");
        gotoxy(38,18);
        printf("Information Saved...Press any key To Continue.");
    }
    else{
        system("cls");
        gotoxy(38,18);
        printf("Signing In Terminated...Press any key To Continue.");
        getch();
        return;
    }
    fclose(fp);
    getch();
}