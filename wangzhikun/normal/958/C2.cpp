#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,k,p,j,u,dp[20005][55][105],y,a[20005];
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&k,&p);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]%p;
	dp[1][1][a[1]]=a[1];
	for(i=1;i<=n;i++)
	{
		y=a[i];
		for(j=1;j<=k;j++)
		{
			for(u=0;u<p;u++)
			{
				if(u==y)dp[i][j][u]=max(dp[i][j][u],(dp[i-1][j][(u-y+p)%p]==-1)?-1:dp[i-1][j][(u-y+p)%p]-(u-y+p)%p+u);
				else if(dp[i-1][j][(u-y+p)%p]!=-1)dp[i][j][u]=dp[i-1][j][(u-y+p)%p]-(u-y+p)%p+u;
				dp[i+1][j+1][a[i+1]]=max(dp[i+1][j+1][a[i+1]],dp[i][j][u]+a[i+1]);
			}
		}
	}
	int ans=-1;
	for(i=0;i<p;i++)ans=max(ans,dp[n][k][i]);
	printf("%d",ans);
	return 0;
}