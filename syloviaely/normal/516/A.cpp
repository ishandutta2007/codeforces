#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int num[50];
int n;
char ch[50];
int main(){
    scanf("%d",&n);
    scanf("%s",ch+1);
    for (int i=1;i<=n;i++){
        int k1=ch[i]-'0';
        if (k1==2||k1==5||k1==7||k1==3) num[k1]++;
        else if (k1==4){num[2]+=2; num[3]++;}
        else if (k1==6){num[3]++; num[5]++;}
        else if (k1==8){num[2]+=3; num[7]++;}
        else if (k1==9){num[3]+=2; num[2]++; num[7]++;}
    }
    for (int i=9;i;i--)
        for (int j=1;j<=num[i];j++) putchar('0'+i);
    return 0;
}