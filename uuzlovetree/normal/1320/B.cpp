#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m,k;
vector<int> g[maxn],g2[maxn];
int p[maxn];
int dis[maxn];
void bfs()
{
	queue<int> q;q.push(p[k]);
	dis[p[k]]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:g[u])if(!dis[v])dis[v]=dis[u]+1,q.push(v);
	}
}
int d[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;++i)scanf("%d",&p[i]);
	bfs();
	for(int u=1;u<=n;++u)
		for(int v:g[u])if(dis[v]==dis[u]+1)g2[u].push_back(v); 
	for(int u=1;u<=n;++u)
		for(int v:g2[u])d[v]++;
	int ans1=0,ans2=0;
	for(int i=1;i<k;++i)
	{
		if(dis[p[i]]!=dis[p[i+1]]+1)ans1++,ans2++;
		else if(d[p[i]]>=2)ans2++;
	}
	printf("%d %d\n",ans1,ans2);
}