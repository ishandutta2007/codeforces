#include <stdio.h>
const int mod=1e9+7;
const int N=1e5+50;
int dp[N];
int main()
{
	int t,k,a,b,i;
	scanf("%i %i",&t,&k);
	dp[0]=1;
	for(i=1;i<N;i++)
	{
		if(i>=k)
		{
			dp[i]=(1ll*dp[i-1]+dp[i-k])%mod;
		}
		else dp[i]=dp[i-1];
	}
	for(i=1;i<N;i++)
	{
		dp[i]=(1ll*dp[i-1]+dp[i])%mod;
	}
	while(t--) scanf("%i %i",&a,&b),printf("%i\n",(1ll*dp[b]-dp[a-1]+mod)%mod);
	return 0;
}