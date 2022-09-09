#include <bits/stdc++.h>
using namespace std;
const int N=16;
const int M=10005;
const int K=1<<N;
const int inf=1e9+7;
int g[N][N],a[N][M];
int dp[K][N][N];
int Solve(int n, int m)
{
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) g[i][j]=inf;
	for(int j=1;j<=m;j++)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n;k++)
			{
				g[i][k]=min(g[i][k],abs(a[i][j]-a[k][j]));
			}
		}
	}
	for(int mask=1;mask<1<<n;mask++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[mask][i][j]=0;
	for(int mask=1;mask<1<<n;mask++)
	{
		for(int i=0;i<n;i++) if((mask>>i)&1)
		{
			for(int j=0;j<n;j++) if((mask>>j)&1)
			{
				if(__builtin_popcount(mask)==1)
				{
					if(i==j) dp[mask][i][j]=inf;
				}
				else
				{
                    for(int l=0;l<n;l++) if((mask>>l)&1)
					{
						dp[mask][i][j]=max(dp[mask][i][j],min(dp[mask^(1<<j)][i][l],g[l][j]));
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
	{
		int tmp=dp[(1<<n)-1][i][j];
		for(int k=1;k<m;k++) tmp=min(tmp,abs(a[j][k]-a[i][k+1]));
		ans=max(ans,tmp);
	}
	return ans;
}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%i",&a[i][j]);
	printf("%i\n",Solve(n,m));
	return 0;
}