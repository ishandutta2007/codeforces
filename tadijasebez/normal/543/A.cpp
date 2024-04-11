#include <stdio.h>
const int N=505;
int mod,a[N],dp[2][N][N],c,p=1;
int main()
{
	int n,m,b,i,j,k;
	scanf("%i %i %i %i",&n,&m,&b,&mod);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	dp[p][0][0]=1;
	for(i=1;i<=n;i++)
	{
		//printf("%i\n",i);
		for(j=0;j<=m;j++)
		{
			for(k=0;k<=b;k++)
			{
				dp[c][j][k]=dp[p][j][k];
				if(a[i]<=k && j) dp[c][j][k]+=dp[c][j-1][k-a[i]];
				if(dp[c][j][k]>=mod) dp[c][j][k]-=mod;
				//printf("%i ",dp[c][j][k]);
			}
			//printf("\n");
		}
		c^=1;p^=1;
	}
	int sol=0;
	for(i=0;i<=b;i++)
	{
		sol+=dp[p][m][i];
		if(sol>=mod) sol-=mod;
	}
	printf("%i\n",sol);
	return 0;
}