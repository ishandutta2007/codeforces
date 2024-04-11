#include<iostream>
using namespace std;
int num[5];
char T_shirt[5][5]={"S","M","L","XL","XXL"};
int select(int a){
    int b=a;
    if(num[a]){
        return a;
    }
    else{
        while(a<5){
            a++;
            if(num[a]){
                return a;
            }
            else if(b>0){
                b--;
                if(num[b]){
                    return b;
                }
            }
        }
        while(b>0){
            b--;
            if(num[b]){
                return b;
            }
        }
    }
}
int main(){
    int k,t,x;
    char people[1010][5];
    while(cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]){
        cin>>k;
        for(int i=0;i<k;i++){
            cin>>people[i];
        }
        for(int i=0;i<k;i++){
            if(people[i][0]=='S'){
                t=0;
            }
            else if(people[i][0]=='M'){
                t=1;
            }
            else if(people[i][0]=='L'){
                t=2;
            }
            else if(people[i][0]=='X'&&people[i][1]=='L'){
                t=3;
            }
            else if(people[i][0]=='X'&&people[i][1]=='X'){
                t=4;
            }
            x=select(t);
            num[x]--;
            cout<<T_shirt[x]<<endl;
        }
    }
    return 0;
}