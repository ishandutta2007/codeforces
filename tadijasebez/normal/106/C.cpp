#include <stdio.h>
long long dp[15][1050];
long long range[15];
long long money[15];
long long cost[15];
long long max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	long long n,m,i,j,a,b,l;
	scanf("%lld %lld %lld %lld",&n,&m,&cost[1],&money[1]);
	range[1]=1000000;
	m++;
	for(i=2;i<=m;i++)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&cost[i],&money[i]);
		range[i]=a/b;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			long long sol=0;
			l=0;
			while(j-l*cost[i]>=0 && l<=range[i])
			{
				sol=max(sol,dp[i-1][j-l*cost[i]]+l*money[i]);
				l++;
			}
			dp[i][j]=sol;
		}
	}
	printf("%lld\n",dp[m][n]);
	return 0;
}