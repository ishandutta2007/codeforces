#include <stdio.h>
const int N=1000;
int dp[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	dp[0]=0;
	int i;
	for(i=1;i<N;i++)
	{
		int sol=N;
		if(i>=1) sol=min(sol,dp[i-1]);
		if(i>=5) sol=min(sol,dp[i-5]);
		if(i>=10) sol=min(sol,dp[i-10]);
		if(i>=20) sol=min(sol,dp[i-20]);
		if(i>=100) sol=min(sol,dp[i-100]);
		dp[i]=sol+1;
	}
	int n;
	scanf("%i",&n);
	int ans=n;
	for(i=0;i<=n/100;i++)
	{
		if(n-i*100<N) ans=min(ans,dp[n-i*100]+i);
	}
	printf("%i",ans);
	return 0;
}