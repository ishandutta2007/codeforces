#include <stdio.h>
#define ll long long
const int N=1550;
const ll inf=1e18;
ll max(ll a, ll b){ return a>b?a:b;}
ll a[N],dp[2][N],c,p=1;
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) scanf("%lld ",&a[j]),a[j]+=a[j-1];
		if(i&1)
		{
			ll Max=-inf;if(i==1) Max=0;
			for(j=1;j<=m;j++) dp[c][j]=Max+a[j],Max=max(Max,dp[p][j]);
		}
		else
		{
			ll Max=-inf;
			for(j=m;j>=1;j--) dp[c][j]=Max+a[j],Max=max(Max,dp[p][j]);
		}
		c^=1;p^=1;
	}
	ll sol=-inf;
	for(i=1;i<=m;i++) sol=max(sol,dp[p][i]);
	printf("%lld\n",sol);
	return 0;
}