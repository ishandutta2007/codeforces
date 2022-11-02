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
const int V=4100;
int dp[810][V],sum[V][V],s[810][V],a[V][V],cost[V][V];
int n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
        }
        for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            cost[i][j]=sum[j][j]+sum[i-1][i-1]-sum[i-1][j]-sum[j][i-1];
        }
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)dp[1][i]=cost[1][i];
        for(int i=1;i<=K;i++)s[i][i]=i-1;
        for(int i=2;i<=K;i++)
        {
            dp[i][n]=oo;
            for(int k=s[i-1][n];k<n;k++)
            {
                int tmp=dp[i-1][k]+cost[k+1][n];
                if(dp[i][n]>tmp)
                {
                    dp[i][n]=tmp;
                    s[i][n]=k;
                }
            }
            for(int j=n-1;j>i;j--)
            {
                dp[i][j]=oo;
                for(int k=s[i-1][j];k<=s[i][j+1];k++)
                {
                    int tmp=dp[i-1][k]+cost[k+1][j];
                    if(dp[i][j]>tmp)
                    {
                        dp[i][j]=tmp;
                        s[i][j]=k;
                    }
                }
            }
        }
        /*for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=oo;
            for(int k=max(s[i][j-1],s[i-1][j]);k<j;k++)
            if(dp[i-1][k]+cost[k+1][j]<dp[i][j])
            {
                dp[i][j]=dp[i-1][k]+cost[k+1][j];
                s[i][j]=k;
            }
        }*/
        printf("%d\n",dp[K][n]/2);
    }
}