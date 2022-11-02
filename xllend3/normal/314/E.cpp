/*
Date: 2014/09/26 10:01:56 Friday
Author: xllend3
*/
#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
using namespace std;
typedef unsigned int u32;
u32 powmod(u32 a,u32 b) {u32 res=1;for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,C,f[N];
char s[N];
int main()
{
    scanf("%d%s",&n,s+1);f[0]=1;int cnt=n,m=n/2;
    rep(i,1,n)if(s[i]=='?'){dep(j,i>>1,i-m<0?0:i-m)f[j]+=f[j-1];--cnt;}
    if(n&1||cnt>m)puts("0");
    else printf("%u\n",f[m]*powmod(25,m-cnt));
    return 0;
}