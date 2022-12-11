#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;
int n,k;
ll a[maxn];
int dp[maxn];
bool check(ll x)
{
	memset(dp,0,sizeof(dp));
	int ans=n;
	for(int i=1;i<=n;++i)
	{
		dp[i]=i-1;
		for(int j=1;j<i;++j)if(abs(a[i]-a[j])<=x*(i-j))
			dp[i]=min(dp[i],dp[j]+(i-j-1));
		ans=min(ans,dp[i]+n-i);
	}
	return (ans<=k);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	ll l=0,r=2000000000,ans=r+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}