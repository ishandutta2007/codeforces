#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,k,d[N][N],ans=1e9,a[N],b[N];
vector<pair<int,int>>e[N];
priority_queue<pair<int,int>>pq;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int u=1;u<=n;u++)
	{
		for(int i=1;i<=n;i++)
			d[u][i]=1e9;
		d[u][u]=0;
		while(!pq.empty())
			pq.pop();
		pq.emplace(0,u);
		while(!pq.empty())
		{
			int r=pq.top().second,dis=pq.top().first;
			pq.pop();
			if(-dis!=d[u][r])
				continue;
			for(auto i:e[r])
			{
				int v=i.first,w=i.second;
				if(d[u][v]>d[u][r]+w)
				{
					d[u][v]=d[u][r]+w;
					pq.emplace(-d[u][v],v);
				}
			}
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(auto it:e[u])
		{
			int v=it.first,s=0;
			for(int i=1;i<=k;i++)
			{
				int x=a[i],y=b[i];
				s+=min(d[x][y],min(d[x][u]+d[y][v],d[x][v]+d[y][u]));
			}
			ans=min(ans,s);
		}
	}
	printf("%d\n",ans);
	return 0;
}