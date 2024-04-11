#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=9e18;
int main()
{
	int n,j,i;
	string s;
	scanf("%i",&n);
	vector<int> a(n);
	cin>>s;
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	vector<vector<ll> > dp;
	dp.assign(n+1,vector<ll>(4,inf));
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<4;j++)
		{
			dp[i][j]=dp[i-1][j];
		}
		if(s[i-1]=='h') dp[i][0]=dp[i-1][0]+a[i-1],dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
		if(s[i-1]=='a') dp[i][1]=dp[i-1][1]+a[i-1],dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
		if(s[i-1]=='r') dp[i][2]=dp[i-1][2]+a[i-1],dp[i][3]=min(dp[i-1][2],dp[i-1][3]);
		if(s[i-1]=='d') dp[i][3]=dp[i-1][3]+a[i-1];
	}
	ll ans=min(dp[n][0],dp[n][1]);
	ans=min(ans,dp[n][2]);
	ans=min(ans,dp[n][3]);
	printf("%lld\n",ans);
	return 0;
}