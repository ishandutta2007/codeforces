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
const int V=610;
const int oo=2000000000;
int dp[2][V][V];
int a[V][V],st[V],ed[V],n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        for(int i=0;i<2*n-1;i++)
        {
            if(i<n)ed[i]=i+1;
            else ed[i]=n-1;
            if(i<n)st[i]=0;
            else st[i]=i-n-1;
        }
        for(int i=0;i<2;i++)
        for(int j=0;j<2*n;j++)
        for(int k=0;k<2*n;k++)
        dp[i][j][k]=-oo;
        dp[0][0][0]=a[0][0];
        int fl=0,te;
        for(int i=0;i<2*n-2;i++)
        {
            te=1-fl;int cost;
            for(int j=0;j<2*n;j++)
            for(int k=0;k<2*n;k++)
            dp[te][j][k]=-oo;
            for(int j=st[i];j<=ed[i];j++)
            for(int k=st[i];k<=ed[i];k++)
            {
               // printf("%d %d %d %d\n",i,j,k,dp[fl][j][k]);
                if(j>=st[i+1]&&k>=st[i+1])
                {
                    cost=a[i+1-j][j];
                    if(j!=k)cost+=a[i+1-k][k];
                    dp[te][j][k]=max(dp[te][j][k],dp[fl][j][k]+cost);
                }
                if(j+1<=ed[i+1]&&k>=st[i+1])
                {
                    cost=a[i+1-j-1][j+1];
                    if(j+1!=k)cost+=a[i+1-k][k];
                    dp[te][j+1][k]=max(dp[te][j+1][k],dp[fl][j][k]+cost);
                }
                if(j>=st[i+1]&&k+1<=ed[i+1])
                {
                    cost=a[i+1-j][j];
                    if(j!=k+1)cost+=a[i+1-k-1][k+1];
                    dp[te][j][k+1]=max(dp[te][j][k+1],dp[fl][j][k]+cost);
                }
                if(j+1<=ed[i+1]&&k+1<=ed[i+1])
                {
                    cost=a[i+1-j-1][j+1];
                    if(j+1!=k+1)cost+=a[i+1-k-1][k+1];
                    dp[te][j+1][k+1]=max(dp[te][j+1][k+1],dp[fl][j][k]+cost);
                }
            }
            fl=te;
        }
        printf("%d\n",dp[fl][n-1][n-1]);
    }
}