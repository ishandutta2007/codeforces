#include <stdio.h>
const int mod=1e9+7;
int dp[500][500];
int main()
{
	int n,m,d,i,j,k;
	scanf("%i %i %i",&m,&n,&d);
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=m;j++)
		{
			for(k=0;k<i;k++)
				dp[i][j]=(1ll*dp[i][j]+dp[k][j-i])%mod;
			for(k=1;k<=i;k++)
				dp[i][j]=(1ll*dp[i][j]+dp[i][j-k])%mod;
		}
	}
	int sol=0;
	for(i=d;i<=n;i++) sol=(1ll*sol+dp[i][m])%mod;
	printf("%i\n",sol);
	return 0;
}