#include<bits/stdc++.h>
#define maxn 4005
using namespace std;
int n,k;
int t[maxn],d[maxn];
int dp[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d%d",&t[i],&d[i]);
	n++;t[n]=86401;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=min(i,k);++j)
		{
			if(!j)dp[i][j]=max(dp[i-1][j]+d[i],t[i]+d[i]-1);
			else dp[i][j]=min(max(dp[i-1][j]+d[i],t[i]+d[i]-1),dp[i-1][j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=min(i,k);++j)
		{
			int p=k-j;
			ans=max(ans,t[min(n,i+p+1)]-dp[i][j]-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}