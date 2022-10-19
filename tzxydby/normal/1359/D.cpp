#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],dp[N][2],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int x=-30;x<=30;x++)
	{
		for(int i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=-1e9;
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=max(dp[i-1][0],0)+a[i];
			dp[i][1]=max(dp[i-1][1],0)+a[i];
			if(a[i]==x)
			{
				dp[i][1]=max(dp[i][1],dp[i][0]);
				dp[i][0]=-1e9;
			}
			if(a[i]>x)
				dp[i][0]=dp[i][1]=-1e9;
		}
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i][1]-x);
	}
	printf("%d\n",ans);
	return 0;
}