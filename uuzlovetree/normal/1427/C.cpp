#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int r,n;
int t[maxn],x[maxn],y[maxn];
int dp[maxn];
int maxv[maxn];
int main()
{
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	int ans=0;
	x[0]=y[0]=1;
	for(int i=1;i<=n;++i)dp[i]=-(int)(1e9+7);
	for(int i=1;i<=n;++i)
	{
		if(i>1000)dp[i]=maxv[i-1000]+1;
		for(int j=i-1;j>=max(0,i-1000);--j)if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))
		{
			dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
		maxv[i]=max(maxv[i-1],dp[i]);
	}
	printf("%d\n",ans);
}