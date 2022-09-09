#include <stdio.h>
const int N=1005;
int dp[N][N][4],a[N][N],sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j]);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
	for(i=n;i>=1;i--) for(j=1;j<=m;j++) dp[i][j][1]=max(dp[i+1][j][1],dp[i][j-1][1])+a[i][j];
	for(i=1;i<=n;i++) for(j=m;j>=1;j--) dp[i][j][2]=max(dp[i-1][j][2],dp[i][j+1][2])+a[i][j];
	for(i=n;i>=1;i--) for(j=m;j>=1;j--) dp[i][j][3]=max(dp[i+1][j][3],dp[i][j+1][3])+a[i][j];
	for(i=2;i<n;i++) for(j=2;j<m;j++)
	{
		sol=max(sol,dp[i-1][j][0]+dp[i][j-1][1]+dp[i][j+1][2]+dp[i+1][j][3]);
		sol=max(sol,dp[i][j-1][0]+dp[i+1][j][1]+dp[i-1][j][2]+dp[i][j+1][3]);
	}
	printf("%i\n",sol);
	return 0;
}