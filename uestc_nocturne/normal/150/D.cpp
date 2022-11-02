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
const int V=152;
const int oo=1000000000;
int dp[V][V][V],ret[V],p[V];
int n;
char s[V];
int dfs(int l,int r,int len)
{
    if(dp[l][r][len]!=-1)return dp[l][r][len];
    if(l>r){if(len)return -oo;return 0;}
    dp[l][r][len]=-oo;
    for(int i=l+1;i<=r;i++)
    {
        dp[l][r][len]=max(dp[l][r][len],dfs(l,i-1,0)+dfs(i,r,len));
        dp[l][r][len]=max(dp[l][r][len],dfs(l,i-1,len)+dfs(i,r,0));
    }
    if(s[l]==s[r])
    {
        int te=len;
        if(l!=r)te++;
        dp[l][r][len]=max(dp[l][r][len],dfs(l+1,r-1,len+2));
        dp[l][r][len]=max(dp[l][r][len],dfs(l+1,r-1,0)+p[te]);
    }
//  printf("%d %d %d %d\n",l,r,len,dp[l][r][len]);
    return dp[l][r][len];
}
int i,j;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            if(p[i]==-1)p[i]=-oo;
        }
        scanf("%s",s);
        memset(dp,-1,sizeof(dp));
        ret[0]=0;
        for(i=1;i<=n;i++)
        {
            ret[i]=ret[i-1];
            for(j=0;j<i;j++)
            ret[i]=max(ret[i],ret[j]+dfs(j,i-1,0));
        }
        printf("%d\n",ret[n]);
    }
}