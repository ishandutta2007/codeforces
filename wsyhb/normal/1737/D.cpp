#include<bits/stdc++.h>
using namespace std;
const int max_n=500+5;
const int max_m=25e4+5;
int dis[max_n][max_n],u[max_m],v[max_m],w[max_m];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=(i!=j?1e9:0);
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d%d",u+i,v+i,w+i);
			dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		long long ans=1e18;
		for(int i=1;i<=m;++i)
		{
			ans=min(ans,(dis[1][u[i]]+dis[v[i]][n]+1ll)*w[i]);
			ans=min(ans,(dis[1][v[i]]+dis[u[i]][n]+1ll)*w[i]);
			for(int x=1;x<=n;++x)
			{
				ans=min(ans,(dis[u[i]][x]+1+dis[x][1]+dis[x][n]+1ll)*w[i]);
				ans=min(ans,(dis[v[i]][x]+1+dis[x][1]+dis[x][n]+1ll)*w[i]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}