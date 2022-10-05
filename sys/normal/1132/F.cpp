#include <bits/stdc++.h>
using namespace std;
string str,s;
int ct,fa[505],ans,n,dp[505][505];
int get_dp(int l,int r)
{
	if(dp[l][r]) return dp[l][r];
	if(l==r) return dp[l][r]=1;
	if(str[l]==str[l+1]) return dp[l][r]=get_dp(l+1,r);
	if(str[r]==str[r-1]) return dp[l][r]=get_dp(l,r-1);
	if(str[l]==str[r]) return dp[l][r]=min(get_dp(l,r-1),get_dp(l+1,r));
	for(int i=l;i<=r;i++)
		dp[l][r]=min(dp[l][r],get_dp(l,i)+get_dp(i,r));
	return dp[l][r];
}
int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int l=n-1;l>=0;l--)
	{
		dp[l][l]=1;
		for(int r=l+1;r<n;r++)
		{
			dp[l][r]=r-l+1;
			if(str[r-1]==str[r]) dp[l][r]=min(dp[l][r],dp[l][r-1]);
			if(str[l]==str[l+1]) dp[l][r]=min(dp[l][r],dp[l+1][r]);
			if(str[l]==str[r])
				dp[l][r]=min(dp[l][r],min(dp[l][r-1],dp[l+1][r]));
			for(int i=l;i<r;i++)
				dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
		}
	}
	printf("%d",dp[0][n-1]);
	return 0;
}