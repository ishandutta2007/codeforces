#include <stdio.h>
const int N=4050;
const int inf=1000000;
int dp[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,a,b,c,i;
	scanf("%i %i %i %i",&n,&a,&b,&c);
	for(i=1;i<=n;i++) dp[i]=-inf;
	for(i=1;i<=n;i++)
	{
		if(i>=a) dp[i]=max(dp[i],dp[i-a]+1);
		if(i>=b) dp[i]=max(dp[i],dp[i-b]+1);
		if(i>=c) dp[i]=max(dp[i],dp[i-c]+1);
	}
	printf("%i\n",dp[n]);
}