#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int k,d,dp[101][2];

int ans(int n,int b)
{
    if(n<0||(b&&n<d))
        return 0;
    if(!b&&n==0)
        return 1;
    if(dp[n][b]!=-1)
        return dp[n][b];
    int res=0;
    for(int i=1;i<d;i++)
        res=(res+ans(n-i,b))%mod;
    for(int i=d;i<=k;i++)
        res=(res+ans(n-i,0))%mod;
    dp[n][b]=res;
    return res;
}

int main()
{
    int n;
    scanf("%d%d%d",&n,&k,&d);
    memset(dp,255,sizeof(dp));
    printf("%d",ans(n,1));
}