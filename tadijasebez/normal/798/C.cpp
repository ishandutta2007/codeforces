#include <stdio.h>
const int N=100050;
const int inf=1e9+7;
int gcd(int x, int y){ return x?gcd(y%x,x):y;}
int min(int a, int b){ return a>b?b:a;}
int dp[N][2],a[N];
int main()
{
	int n,i,g=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),g=gcd(g,a[i]),a[i]%=2;
	if(g>1) return printf("YES\n0\n"),0;
	for(i=0;i<N;i++) dp[i][0]=dp[i][1]=inf;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			dp[i][0]=dp[i-1][1]+1;
			dp[i][0]=min(dp[i][0],dp[i-1][0]+2);
			dp[i][1]=dp[i-1][0];
		}
		else
		{
			dp[i][0]=dp[i-1][0];
			dp[i][0]=min(dp[i][0],dp[i-1][1]+2);
		}
		//printf("%i %i %i\n",i,dp[i][0],dp[i][1]);
	}
	printf("YES\n");
	printf("%i\n",dp[n][0]);
	return 0;
}