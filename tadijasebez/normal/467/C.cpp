#include <stdio.h>
const int N=5050;
long long a[N];
long long dp[N][N];
long long max(long long a, long long b){ return a>b?a:b;}
int main()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(j=1;j<=k;j++)
	{
		for(i=1;i<=n;i++)
		{
			dp[j][i]=dp[j][i-1];
			if(i>=m) dp[j][i]=max(dp[j][i],dp[j-1][i-m]+a[i]-a[i-m]);
		}
	}
	printf("%lld\n",dp[k][n]);
	return 0;
}