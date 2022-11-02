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
const LL ooo=1000000000;
const LL oo=ooo*ooo;
const int V=100100;
LL a[V],b[V],s[V],dp[V];
LL f1(int x,int y)
{
    return -(dp[x]-dp[y]);
}
LL f2(int x,int y)
{
    return b[x]-b[y];
}
int n,q[V];
int main()
{
    //freopen("EE.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        s[0]=a[0];
        for(int i=1;i<n;i++)s[i]=s[i-1]+a[i];
        dp[0]=0;
        int top=0,tail=1;q[1]=0;
        for(int i=1;i<n;i++)
        {
            while(top+1<tail&&f1(q[top+2],q[top+1])>=f2(q[top+2],q[top+1])*a[i])top++;
            //printf("%d %d\n",i,q[top+1]);
            dp[i]=dp[q[top+1]]+b[q[top+1]]*a[i];
            while(top+1<tail&&1.0*f1(i,q[tail])*f2(q[tail],q[tail-1])<=1.0*f2(i,q[tail])*f1(q[tail],q[tail-1]))tail--;
            q[++tail]=i;
            //for(int j=top+1;j<=tail;j++)printf("%d ",q[j]);puts("");
        }
        cout<<dp[n-1]<<endl;
    }
}