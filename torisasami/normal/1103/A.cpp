#include<iostream>
using namespace std;
int main(){
    int i,flag[2];
    char s[333333];
    for(i=0;i<333333;i++)
    s[i]='\0';
    flag[0]=0;
    flag[1]=0;
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='0'){
            if(flag[0]==0){
                cout<<"1 1"<<endl;
                flag[0]++;
            }
            else if(flag[0]==1){
                cout<<"1 2"<<endl;
                flag[0]++;
            }
            else if(flag[0]==2){
                cout<<"1 3"<<endl;
                flag[0]++;
            }
            else{
                cout<<"1 4"<<endl;
                flag[0]=0;
            }
        }
        else{
            if(flag[1]==0){
                cout<<"3 1"<<endl;
                flag[1]++;
            }
            else{
                cout<<"3 3"<<endl;
                flag[1]=0;
            }
        }
    }
}