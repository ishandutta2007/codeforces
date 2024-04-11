#include <stdio.h>
const int N=100050;
const int inf=1000000000;
long long x[N],h[N];
int dp[N][2];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&x[i],&h[i]);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	dp[1][0]=1;
	dp[1][1]=x[2]<x[1]+h[1]?1:-inf;
	for(i=2;i<n;i++)
	{
		if(x[i]-h[i]>x[i-1]+h[i-1])
		{
			dp[i][0]=max(dp[i-1][1],dp[i-1][0])+1;
		}
		else if(x[i]-h[i]>x[i-1])
		{
			dp[i][0]=dp[i-1][0]+1;
		}
		else dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(x[i]+h[i]<x[i+1])
		{
			dp[i][1]=max(dp[i-1][1],dp[i-1][0])+1;
		}
		else dp[i][1]=-inf;
	}
	printf("%i\n",max(dp[n-1][0],dp[n-1][1])+1);
	return 0;
}