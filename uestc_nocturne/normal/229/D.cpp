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
const int oo=1000000000;
const int V=5100;
int dp[V][V],ma,n,h[V],s[V];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
        s[0]=0;
        for(int i=1;i<=n;i++)
        s[i]=s[i-1]+h[i];
        for(int i=1;i<=n;i++)
        dp[1][i]=1;
        for(int i=2;i<=n;i++)
        {
            int p=i;
            ma=-oo;
            for(int j=i;j<=n;j++)
            {
                while(p-1>0&&s[i-1]-s[p-2]<=s[j]-s[i-1])
                {p--;ma=max(ma,dp[p][i-1]);}
                dp[i][j]=ma+1;
            //  printf("%d %d %d %d\n",i,j,p,dp[i][j]);
            }
        }
        int ret=0;
        for(int i=1;i<=n;i++)
        ret=max(ret,dp[i][n]);
        printf("%d\n",n-ret);
    }
}