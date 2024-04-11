#include <stdio.h>
const int N=105;
int dp[N];
int a[N];
int sol=-10000000,ans;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) ans+=a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]) dp[i]=dp[i-1]-1;
		else dp[i]=dp[i-1]+1;
		sol=max(sol,dp[i]);
		if(dp[i]<0) dp[i]=0;
	}
	printf("%i\n",ans+sol);
	return 0;
}