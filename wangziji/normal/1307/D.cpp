#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct edge
{
	int v,n,w;
}e[500005];
int head[500005],cnt,dis[500005],DIS[500005],vis[500005];
inline void add(int u,int v,int w)
{
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
priority_queue <pair<int,int>,vector <pair<int,int> >,greater <pair<int,int> > > q;
int t[500005];
pair <int,int> b[500005];
int main(int argc, char** argv) {
	int n,m,k,s=1;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++)
		cin >> t[i];
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v;
		add(u,v,1);
		add(v,u,1);
	}
	q.push({0,s});
	for(int i=1;i<=n;i++)
		dis[i]=2e9;
	dis[s]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].n)
		{
			if(dis[e[i].v]>dis[x]+e[i].w)
			{
				dis[e[i].v]=dis[x]+e[i].w;
				q.push({dis[e[i].v],e[i].v});
			}
		}
	}
	s=n;
	q.push({0,s});
	for(int i=1;i<=n;i++)
		DIS[i]=2e9,vis[i]=0;
	DIS[s]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].n)
		{
			if(DIS[e[i].v]>DIS[x]+e[i].w)
			{
				DIS[e[i].v]=DIS[x]+e[i].w;
				q.push({DIS[e[i].v],e[i].v});
			}
		}
	}
	for(int i=1;i<=k;i++)
		b[i]={dis[t[i]],DIS[t[i]]};
	sort(b+1,b+k+1);
	for(int i=k;i>=1;i--)
		b[i].second=max(b[i].second,b[i+1].second);
	int now=1,ans=0;
	for(int i=1;i<=k;i++)
	{
		while(min(b[i].first+b[now].second,b[i].second+b[now].first)<min(b[i].first+b[now+1].second,b[i].second+b[now+1].first))
		{
			++now;
		//	cout << i << " "<< now << " "<< min(b[i].first+b[now].second,b[i].second+b[now].first) << " " << min(b[i].first+b[now-1].second,b[i].second+b[now-1].first)	<< endl;
		}
		if(i!=now)
			ans=max(ans,min(b[i].first+b[now].second,b[i].second+b[now].first));
		if(now-1!=i)
			ans=max(ans,min(b[i].first+b[now-1].second,b[i].second+b[now-1].first));
		if(now+1!=i)
			ans=max(ans,min(b[i].first+b[now+1].second,b[i].second+b[now+1].first));
	}
	cout << min(ans+1,dis[n]);
	return 0;
}