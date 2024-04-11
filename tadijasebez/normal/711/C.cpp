#include <stdio.h>
#define ll long long
const int N=105;
const ll inf=1e15;
ll dp[N][N][N];
int cost[N][N],c[N];
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int n,m,k,i,j,l,r;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&cost[i][j]);
	for(i=0;i<N;i++) for(j=0;j<N;j++) for(l=0;l<N;l++) dp[i][j][l]=inf;
	if(c[1])
	{
		dp[1][c[1]][1]=0;
	}
	else
	{
		for(i=1;i<=m;i++) dp[1][i][1]=cost[1][i];
	}
	for(i=2;i<=n;i++)
	{
		if(c[i])
		{
			for(j=1;j<=k;j++)
			{
				for(l=1;l<=m;l++)
				{
					if(l==c[i]) dp[i][c[i]][j]=min(dp[i][c[i]][j],dp[i-1][l][j]);
					else dp[i][c[i]][j]=min(dp[i][c[i]][j],dp[i-1][l][j-1]);
				}
			}
		}
		else
		{
			for(j=1;j<=k;j++)
			{
				for(l=1;l<=m;l++)
				{
					for(r=1;r<=m;r++)
					{
						if(l==r) dp[i][l][j]=min(dp[i][l][j],dp[i-1][r][j]+cost[i][l]);
						else dp[i][l][j]=min(dp[i][l][j],dp[i-1][r][j-1]+cost[i][l]);
					}
				}
			}
		}
	}
	ll sol=inf;
	for(i=1;i<=m;i++) sol=min(sol,dp[n][i][k]);
	if(sol<inf) printf("%lld\n",sol);
	else printf("-1\n");
	return 0;
}