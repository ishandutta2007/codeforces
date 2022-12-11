#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int pd[30];
        for(int i=0;i<3;i++)pd[i]=0;
        int ans=0;
        for(char kk:s){
            if(kk=='r')pd[0]=1;
            if(kk=='g')pd[1]=1;
            if(kk=='b')pd[2]=1;
            if(kk=='R')if(!pd[0])ans=1;
            if(kk=='G')if(!pd[1])ans=1;
            if(kk=='B')if(!pd[2])ans=1;
        }
        puts(ans?"NO":"YES");
    }
    return  0;
}