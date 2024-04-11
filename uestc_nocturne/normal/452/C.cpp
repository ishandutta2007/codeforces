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
const int V=1200;
int n,m;
double dp[V][V];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1.0;
        for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
        {
            double p=1.0*(m-j)/(n*m-i);
            dp[i+1][j+1]+=dp[i][j]*p;
            dp[i+1][j]+=dp[i][j]*(1-p);
        }
        double ret=0.0;
        for(int j=1;j<=m;j++)
        ret+=dp[n][j]*j/n*j/n;
        ret*=n;
        printf("%.10f\n",ret);
    }
}