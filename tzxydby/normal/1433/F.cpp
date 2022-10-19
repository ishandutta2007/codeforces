#include<bits/stdc++.h>
using namespace std;
const int N=75;
int dp[N][N][N/2][N],n,m,k,a[N][N];
void chmax(int &a,int b){if(a<b)a=b;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	memset(dp,-1,sizeof(dp));
	dp[0][0][0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int x=0;x<=m/2;x++)
			{
				for(int y=0;y<k;y++)
				{
					if(dp[i][j][x][y]==-1)
						continue;
					if(j==m)
						chmax(dp[i+1][0][0][y],dp[i][j][x][y]);
					else
					{
						chmax(dp[i][j+1][x][y],dp[i][j][x][y]);
						chmax(dp[i][j+1][x+1][(y+a[i][j+1])%k],dp[i][j][x][y]+a[i][j+1]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[n+1][0][0][0]);
	return 0;
}