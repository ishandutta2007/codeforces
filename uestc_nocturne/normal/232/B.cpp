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
int C[120][120],dp[120][12000];
int Pow(int x,LL y)
{
    LL ret=1;
    while(y)
    {
        if(y&1)ret=(ret*x)%P;
        y/=2;x=(LL)x*x%P;
    }
    return (int)ret;
}
int va[2][120];
LL m;
int n,K;
int main()
{
    for(int i=0;i<110;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
    }
    while(~scanf("%d%I64d%d",&n,&m,&K))
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        LL tm=m/n;
        int re=m%n;
        for(int i=0;i<=n;i++)va[0][i]=Pow(C[n][i],tm);
        for(int i=0;i<=n;i++)va[1][i]=Pow(C[n][i],tm+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i*n;j++)
            {
        //      printf("%d %d %d\n",i,j,dp[i][j]);
                for(int k=0;k<=n;k++)
                {
                    int tmp;
                    if(i<re)tmp=va[1][k];
                    else tmp=va[0][k];
                    dp[i+1][j+k]+=(LL)tmp*dp[i][j]%P;
                    dp[i+1][j+k]%=P;
                }
            }
        }
        printf("%d\n",dp[n][K]);
    }
}