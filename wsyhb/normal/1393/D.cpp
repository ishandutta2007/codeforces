#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e3+5;
char Map[N][N];
int dp[N][N][4];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",Map[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j][0]=(Map[i][j]==Map[i-1][j]&&Map[i][j]==Map[i][j-1]?min(dp[i-1][j][0],dp[i][j-1][0]):0)+1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			dp[i][j][1]=(Map[i][j]==Map[i-1][j]&&Map[i][j]==Map[i][j+1]?min(dp[i-1][j][1],dp[i][j+1][1]):0)+1;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			dp[i][j][2]=(Map[i][j]==Map[i+1][j]&&Map[i][j]==Map[i][j-1]?min(dp[i+1][j][2],dp[i][j-1][2]):0)+1;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			dp[i][j][3]=(Map[i][j]==Map[i+1][j]&&Map[i][j]==Map[i][j+1]?min(dp[i+1][j][3],dp[i][j+1][3]):0)+1;
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int cnt=1e9;
			for(int k=0;k<4;k++) cnt=min(cnt,dp[i][j][k]);
			ans+=cnt;
		}
	printf("%lld",ans);
	return 0;
}