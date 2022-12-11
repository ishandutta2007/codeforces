#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 1000005
using namespace std;
int n,m;
int has[maxn];
int dp[maxn][3][3];
int main()
{
	scanf("%d%d",&n,&m);
	for(int x,i=1;i<=n;++i)
	{
		scanf("%d",&x);
		has[x]++;
	}
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=2;++j)
		{
			for(int k=0;k<=2;++k)dp[i][j][k]=-inf;
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<=min(has[i],2);++j)
		{
			for(int k=0;k<=min(has[i+1],2);++k)
			{
				for(int l=0;l<=min(has[i+2],2);++l)if(has[i+1]>=j+k+l)
				{
					dp[i+1][k][l]=max(dp[i+1][k][l],dp[i][j][k]+l+(has[i+1]-j-k-l)/3);
				}
			}
		}
	}
	printf("%d\n",dp[m][0][0]);
	return 0;
}