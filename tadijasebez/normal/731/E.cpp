#include <stdio.h>
#define ll long long
const int N=200050;
ll dp[N][2],a[N];
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int n,i;
	scanf("%i",&n);
	ll Max=-9e18,Min=9e18;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	Max=a[n];Min=-a[n];
	dp[n][0]=dp[n][1]=0;
	for(i=n-1;i;i--)
	{
		dp[i][0]=Max;
		dp[i][1]=Min;
		Min=min(Min,dp[i][0]-a[i]);
		Max=max(Max,dp[i][1]+a[i]);
	}
	printf("%lld\n",dp[1][0]);
	return 0;
}