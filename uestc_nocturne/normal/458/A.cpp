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
const double eps=1e-12;
const int V=100100;
const int N=100000;
int a[V],b[V];
char s[V];
int elfcmp()
{
    int mi=0;
    for(int i=N;i>1;i--)
    {
        if(a[i]==b[i])continue;
        mi=min(a[i],b[i]);
        a[i]-=mi;b[i]-=mi;
        if(a[i]>N)return 1;
        if(b[i]>N)return -1;
        a[i-1]+=a[i];a[i-2]+=a[i];
        b[i-1]+=b[i];b[i-2]+=b[i];
    }
    a[1]-=b[1];
    a[0]-=b[0];
    double z=sqrt(5.0)*a[1]+2*a[0]+a[1];
    if(z>eps)return 1;
    else if(z<-eps)return -1;
    else return 0;
    LL x=5*(LL)a[1]*a[1];
    LL y=(LL)(2*a[0]-a[1])*(2*a[0]-a[1]);
    if(x>y)return 1;
    if(x<y)return -1;
    else return 0;
}
int main()
{
    while(~scanf("%s",s))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n=strlen(s);
        for(int i=0;i<n;i++)
        a[n-1-i]=s[i]-'0';
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++)
        b[n-1-i]=s[i]-'0';
        int ret=elfcmp();
        if(ret==-1)puts("<");
        else if(ret==1)puts(">");
        else puts("=");
    }
    return 0;
}