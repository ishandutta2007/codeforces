#include <stdio.h>
const int mod=1e8;
int dp[105][105][2];
int main()
{
	int n1,n2,k1,k2,i,j,l;
	scanf("%i %i %i %i",&n1,&n2,&k1,&k2);
	dp[0][0][0]=dp[0][0][1]=1;
	for(i=0;i<=n1;i++)
		for(j=0;j<=n2;j++)
		{
			for(l=1;l<=i && l<=k1;l++) dp[i][j][0]=(dp[i][j][0]+dp[i-l][j][1])%mod;
			for(l=1;l<=j && l<=k2;l++) dp[i][j][1]=(dp[i][j][1]+dp[i][j-l][0])%mod;
		}
	printf("%i\n",(dp[n1][n2][0]+dp[n1][n2][1])%mod);
	return 0;
}