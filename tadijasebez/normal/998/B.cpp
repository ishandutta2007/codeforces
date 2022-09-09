#include <stdio.h>
const int N=105;
const int inf=1e9;
int a[N],sum[N],dp[N][N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,b,i,j,k;
	scanf("%i %i",&n,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]&1) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
	}
	for(i=0;i<N;i++) for(j=0;j<N;j++) dp[i][j]=-inf;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=b;j++)
		{
			if(sum[i]==0)
			{
				dp[i][j]=dp[0][j];
			}
			for(k=1;k<i;k++)
			{
				if(sum[i]==sum[k])
				{
					int cost=a[k]-a[k+1];
					if(cost<0) cost=-cost;
					if(cost<=j)
					{
						dp[i][j]=max(dp[i][j],dp[k][j-cost]+1);
					}
				}
			}
		}
	}
	int sol=-inf;
	for(i=0;i<=b;i++) sol=max(sol,dp[n][i]);
	printf("%i\n",sol);
	return 0;
}