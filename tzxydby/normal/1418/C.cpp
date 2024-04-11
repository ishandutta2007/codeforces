#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],dp[N][2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=1e9;
		dp[0][0]=0;
		for(int i=0;i<n;i++)
		{
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]+a[i+1]);
			dp[i+2][1]=min(dp[i+2][1],dp[i][0]+a[i+1]+a[i+2]);
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
			dp[i+2][0]=min(dp[i+2][0],dp[i][1]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
	return 0;
}