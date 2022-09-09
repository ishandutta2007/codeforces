#include <stdio.h>
const int N=300050;
const int M=35;
const int inf=1e9+7;
int dp[N][M],a[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=0;i<=n;i++) for(j=0;j<M;j++) dp[i][j]=inf;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		a[i]/=100;
		for(j=0;j<M;j++)
		{
			if(j+a[i]/10<M) dp[i][j+a[i]/10]=min(dp[i][j+a[i]/10],dp[i-1][j]+a[i]);
			int l=min(a[i],j);
			for(k=1;k<=l;k++)
			{
				dp[i][j-k]=min(dp[i][j-k],dp[i-1][j]+a[i]-k);
			}
		}
	}
	int ans=inf;
	for(i=0;i<M;i++) ans=min(ans,dp[n][i]);
	printf("%i\n",ans*100);
	return 0;
}