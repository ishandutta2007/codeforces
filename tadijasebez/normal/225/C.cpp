#include <stdio.h>
#include <cstring>
const int N=1005;
const int inf=1e9+7;
int cost[N],dp[N][N][2];
char s[N][N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,x,y,i,j;
	scanf("%i %i %i %i",&n,&m,&x,&y);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++) cost[j]+=s[i][j]=='#';
	}
	for(i=0;i<N;i++) for(j=0;j<N;j++) dp[i][j][0]=dp[i][j][1]=inf;
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=y;j++) dp[i][j][0]=dp[i-1][j-1][0]+n-cost[i];
		for(j=1;j<=y;j++) dp[i][j][1]=dp[i-1][j-1][1]+cost[i];
		for(j=x;j<=y;j++) dp[i][1][0]=min(dp[i][1][0],dp[i-1][j][1]+n-cost[i]);
		for(j=x;j<=y;j++) dp[i][1][1]=min(dp[i][1][1],dp[i-1][j][0]+cost[i]);
	}
	int sol=inf;
	for(i=x;i<=y;i++) sol=min(sol,dp[m][i][0]),sol=min(sol,dp[m][i][1]);
	printf("%i\n",sol);
	return 0;
}