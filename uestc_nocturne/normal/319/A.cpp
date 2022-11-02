/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int P=1000000007;
char s[120];
int n,pt[220];
int main()
{
    pt[0]=1;
    for(int i=1;i<=210;i++)
    pt[i]=pt[i-1]*2%P;
    while(~scanf("%s",s))
    {
        n=strlen(s);
        int ret=0;
        for(int i=0;i<n;i++)
        if(s[i]=='1')
        ret=(ret+pt[i+2*(n-i-1)])%P;
        if(n==1&&s[0]=='1')ret=1;
        printf("%d\n",ret);
    }
}