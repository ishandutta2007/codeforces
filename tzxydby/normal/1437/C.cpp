#include<bits/stdc++.h>
using namespace std;
const int N=405;
int t,n,a[N],dp[N][N],ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=0;i<=400;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=1e9;
		dp[0][0]=0;
		ans=1e9;
		for(int i=0;i<=400;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dp[i][j]==1e9)
					continue;
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(i+1-abs(a[j+1])));
			}
			ans=min(ans,dp[i][n]);
		}
		printf("%d\n",ans);
	}
	return 0;
}