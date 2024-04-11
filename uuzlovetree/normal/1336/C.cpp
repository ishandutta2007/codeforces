#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
char s[3005],t[3005];
int n,m;
int dp[3005][3005];
bool vis[3005][3005];
int dfs(int l,int r)
{
	if(vis[l][r])return dp[l][r];
	vis[l][r]=1;
	if(l==r)
	{
		if(l<=m)
		{
			if(t[l]==s[1])dp[l][r]=2;
			else dp[l][r]=0;
		}
		else dp[l][r]=2;
		return dp[l][r];
	}
	if(l<=m)
	{
		if(t[l]==s[r-l+1])dp[l][r]=(dp[l][r]+dfs(l+1,r))%mod;
	}
	else
	{
		dp[l][r]=(dp[l][r]+dfs(l+1,r))%mod;
	}
	if(r<=m)
	{
		if(t[r]==s[r-l+1])dp[l][r]=(dp[l][r]+dfs(l,r-1))%mod;
	}
	else
	{
		dp[l][r]=(dp[l][r]+dfs(l,r-1))%mod;
	}
	return dp[l][r];
}
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	int ans=0;
	for(int i=m;i<=n;++i)ans=(ans+dfs(1,i))%mod;
	printf("%d\n",ans);
}