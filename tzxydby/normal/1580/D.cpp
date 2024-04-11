#include<bits/stdc++.h>
using namespace std;
const int N=4005;
const long long inf=1e18;
int n,m,a[N],sz[N];
long long dp[N][N];
int sol(int l,int r)
{
	if(l>r)
		return 0;
	int u=l;
	for(int i=l;i<=r;i++)
		if(a[i]<a[u])
			u=i;
	int lc=sol(l,u-1),rc=sol(u+1,r);
	sz[u]=sz[lc]+sz[rc]+1;
	dp[u][1]=1ll*a[u]*(m-1);
	for(int i=0;i<=sz[lc];i++)
	{
		for(int j=0;j<=sz[rc];j++)
		{
			if(dp[lc][i]>-inf&&dp[rc][j]>-inf)
			{
				dp[u][i+j]=max(dp[u][i+j],dp[lc][i]+dp[rc][j]-2ll*i*j*a[u]);
				dp[u][i+j+1]=max(dp[u][i+j+1],dp[lc][i]+dp[rc][j]-2ll*i*j*a[u]+1ll*a[u]*(m-1)-2ll*(i+j)*a[u]);
			}
		}
	}
	return u;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=-inf;
	dp[0][0]=0;
	int c=sol(1,n);
	printf("%lld\n",dp[c][m]);
	return 0;
}