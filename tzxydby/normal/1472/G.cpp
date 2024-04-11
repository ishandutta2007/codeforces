#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,d[N],dis[N],t[N];
queue<int>q;
vector<int>e[N],g[N];
priority_queue<pair<int,int>>pq;
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		d[i]=-1;
		e[i].clear();
		g[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		g[v].push_back(u);
	}
	while(!q.empty())
		q.pop();
	d[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			if(d[v]==-1)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i]=d[i];
		pq.emplace(-dis[i],i);
	}
	while(!pq.empty())
	{
		int u=pq.top().second,y=-pq.top().first;
		pq.pop();
		if(dis[u]!=y)
			continue;
		for(auto v:g[u])
		{
			if(d[v]<d[u])
			{
				if(dis[v]>dis[u])
				{
					dis[v]=dis[u];
					pq.emplace(-dis[v],v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		t[i]=dis[i];
	for(int u=1;u<=n;u++)
		for(auto v:g[u])
			if(d[v]>=d[u])
				t[v]=min(t[v],dis[u]);
	for(int i=1;i<=n;i++)
	{
		dis[i]=t[i];
		pq.emplace(-dis[i],i);
	}
	while(!pq.empty())
	{
		int u=pq.top().second,y=-pq.top().first;
		pq.pop();
		if(dis[u]!=y)
			continue;
		for(auto v:g[u])
		{
			if(d[v]<d[u])
			{
				if(dis[v]>dis[u])
				{
					dis[v]=dis[u];
					pq.emplace(-dis[v],v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}