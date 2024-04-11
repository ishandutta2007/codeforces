#pragma GCC optimize("Ofast",3,"inline") 
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
long long dis[N][N];
vector<pair<int,int>>e[N];
priority_queue<pair<long long,int>>q;
void dijkstra(int x)
{
	dis[x][x]=0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		long long k=-q.top().first;
		int v=q.top().second;
		q.pop();
		if(k!=dis[x][v])
			continue;
		for(int i=0;i<(int)e[v].size();i++)
		{
			int w=e[v][i].first;
			long long l=e[v][i].second;
			if(dis[x][w]>k+l)
			{
				dis[x][w]=k+l;
				q.push(make_pair(-dis[x][w],w));
			}
		}
	}
}
int main()
{
	int n,m,s,f,u,v,w,t,c;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=LLONG_MAX/2;
	for(int i=1;i<=n;i++)
		dijkstra(i);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t,&c);
		for(int j=1;j<=n;j++)
			if(dis[i][j]<=t)
				e[i].push_back(make_pair(j,c));		
	}
	for(int i=1;i<=n;i++)
		dis[s][i]=LLONG_MAX/2;
	dijkstra(s);
	if(dis[s][f]==LLONG_MAX/2)
		printf("-1\n");
	else
		printf("%I64d\n",dis[s][f]);
	return 0;
}