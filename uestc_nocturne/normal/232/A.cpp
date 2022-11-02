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
bool co[120][120];
int k;
int dp[1000000],m;
int main()
{
    while(~scanf("%d",&k))
    {
        int n=3;
        while(1)
        {
            int tt=n*(n-1)*(n-2)/6;
            if(tt>k)break;
            n++;
        }
        n--;
        int re=k-n*(n-1)*(n-2)/6;
    //  printf("%d %d\n",n,re);
        memset(co,0,sizeof(co));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        co[i][j]=1;
        for(int i=0;i<n;i++)co[i][i]=0;
        for(int i=0;i<=re;i++)dp[i]=100000;
        dp[0]=0;
        for(int i=2;i<=n;i++)
        {
            int ct=i*(i-1)/2;
            for(int j=ct;j<=re;j++)
            dp[j]=min(dp[j],dp[j-ct]+1);
        }
        int now=re;
    //  printf("%d %d\n",re,dp[re]);
//      for(int i=0;i<=re;i++)printf("%d ",dp[i]);puts("");
        for(int i=n;i<n+dp[re];i++)
        {
            int pr=-1;
            for(int j=2;j<=n;j++)
            {
                int ct=j*(j-1)/2;
                if(ct<=now&&dp[now]==dp[now-ct]+1)
                {pr=j;break;}
            }
            if(pr==-1)while(1);
            for(int j=0;j<pr;j++)co[j][i]=co[i][j]=1;
            now-=pr*(pr-1)/2;
        }
        m=n+dp[re];
        printf("%d\n",m);
        for(int i=0;i<m;i++,puts(""))
        for(int j=0;j<m;j++)printf("%d",co[i][j]);
    }
}