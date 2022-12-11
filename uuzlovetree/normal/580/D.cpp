#include<bits/stdc++.h>
#define ll long long
#define maxn 20
#define maxs 500005
using namespace std;
int n,m,k;
ll a[maxn];
int c[maxn][maxn];
ll dp[maxs][maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int fullset=(1<<n)-1;
	for(int i=0;i<n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=k;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		scanf("%d",&c[u][v]);
	}
	for(int i=0;i<n;++i)dp[1<<i][i]=a[i];
	for(int S=0;S<fullset;++S)
	{
		for(int last=0;last<n;++last)if(S&(1<<last))
		{
			for(int i=0;i<n;++i)if(!(S&(1<<i)))
			{
				dp[S|(1<<i)][i]=max(dp[S|(1<<i)][i],dp[S][last]+a[i]+c[last][i]);
			}
		}
	}
	ll ans=0;
	for(int S=0;S<=fullset;++S)
	{
		int tot=0;
		for(int i=0;i<n;++i)if(S&(1<<i))tot++;
		if(tot==m)
		{
			for(int i=0;i<n;++i)ans=max(dp[S][i],ans);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}