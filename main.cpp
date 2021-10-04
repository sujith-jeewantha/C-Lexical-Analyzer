#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){
char keywords[48][10] = {"asm","double","new","switch","auto","else","operator",
                                "template","break","enum","private","this","case","extern","protected",
                                "throw","catch","float","public","try","char","for",
                                "register","typedef","class","friend","return","union",
                                "const","goto","short","unsigned","continue","if","signed","virtual","default","inline",
                                "sizedof","void","delete","int","static","volatile","do","long","struct","while"};
int i, flag = 0;
    for(i = 0; i < 48; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

return flag;
}

int main(){

char inputs,
        buffer[15],
        operators[] = "+-*/%=",
        numbers[] = "0123456789";

ifstream fin("inputs.txt");

int i,j=0;
    if(!fin.is_open()){
        cout<<"error occured while opening the file\n";
        exit(0);
    }

while(!fin.eof()){
   inputs = fin.get();

for(i = 0; i < 10; ++i){

       if(inputs == operators[i])
       {
        cout<<inputs<<" is operator\n";
       }

       else if (inputs == numbers[i])
       {
        cout<<inputs<<" is number\n";
       }
   }

   if(isalnum(inputs)){
   buffer[j++] = inputs;
   }
   else if((inputs == ' ' || inputs == '\n') && (j != 0)){
   buffer[j] = '\0';
   j = 0;

   if(isKeyword(buffer) == 1)
   cout<<buffer<<" is keyword\n";
   else
   cout<<buffer<<" is indentifier\n";
   }

}
fin.close();
return 0;
}
