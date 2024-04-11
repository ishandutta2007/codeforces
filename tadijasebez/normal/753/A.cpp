#include <stdio.h>
const int N=1050;
const int inf=7777777;
int max(int a, int b){ return a>b?a:b;}
int dp[N][N],go[N][N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<N;i++) for(j=0;j<N;j++) dp[i][j]=-inf;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j<i) dp[i][j]=dp[i-1][j],go[i][j]=0;
			else if(dp[i-1][j]>dp[i-1][j-i]) dp[i][j]=dp[i-1][j],go[i][j]=0;
			else dp[i][j]=dp[i-1][j-i]+1,go[i][j]=1;
		}
	}
	printf("%i\n",dp[n][n]);
	i=n;j=n;
	while(j+i!=0)
	{
		if(go[i][j]) printf("%i ",i),j-=i;
		i--;
	}
	printf("\n");
	return 0;
}