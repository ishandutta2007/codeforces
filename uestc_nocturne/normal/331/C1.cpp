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
const int V=1001000;
int dp[V];
int pt[120];
int dfs(int n)
{
    if(dp[n]!=-1)return dp[n];
    dp[n]=V;
    for(int i=0;i<7;i++)
    {
        int sub=(n/pt[i])%10;
        if(sub!=0)
        dp[n]=min(dp[n],dfs(n-sub)+1);
    }
    return dp[n];
}
int n;
int main()
{
    pt[0]=1;
    for(int i=1;i<=10;i++)pt[i]=pt[i-1]*10;
    while(~scanf("%d",&n))
    {
        memset(dp,0-1,sizeof(dp));
        dp[0]=0;
        printf("%d\n",dfs(n));
    }
    return 0;
}