#include<bits/stdc++.h>
using namespace std;
int n,a[19],num[19];
char s[19];

int main(){
    memset(num,0,sizeof(num));
    scanf("%d%s",&n,s);
    for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++)
        if(a[i]>1) num[a[i]]++;
    if(num[9]){
        num[7]+=num[9];
        num[3]+=2*num[9];
        num[2]+=num[9];
        num[9]=0;
    }
    if(num[8]){
        num[7]+=num[8];
        num[2]+=3*num[8];
        num[8]=0;
    }
    if(num[6]){
        num[5]+=num[6];
        num[3]+=num[6];
        num[6]=0;
    }
    if(num[4]){
        num[2]+=2*num[4];
        num[3]+=num[4];
        num[4]=0;
    }
    for(int i=9;i>=2;i--)
        while(num[i]){
            printf("%d",i);
            num[i]--;
        }
    return 0;
}
/*
9!=9*8*7*6*5*4*3*2
->7!*3!*3!*2!
8!->7!*2!*2!*2!
7!
6!=5!*3!
5!
4!=2!*2!*3!
3!
2!


*/