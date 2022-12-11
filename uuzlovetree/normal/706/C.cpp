#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
const ll inf = (ll)1e18+1;
int n;
string s[maxn],rs[maxn];
ll c[maxn],dp[maxn][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)
	{
		int len=s[i].length();
		for(int j=0;j<len;++j)rs[i].push_back(s[i][len-j-1]);
	}
	dp[1][0]=0;dp[1][1]=c[1];
	for(int i=2;i<=n;++i)
	{
		dp[i][0]=inf;dp[i][1]=inf;
		if(s[i-1]<=s[i])dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(rs[i-1]<=s[i])dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(s[i-1]<=rs[i])dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		if(rs[i-1]<=rs[i])dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
	}
	ll ans=min(dp[n][0],dp[n][1]);
	if(ans==inf)puts("-1");
	else cout<<ans<<endl;
	return 0;
}