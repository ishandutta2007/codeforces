#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=20005,INF=1e9;
	int n,s,t,mf;
	struct edge
	{
		int v,f,nxt;
	}e[N];
	int head[N],cur[N],cnt,vis[N];
	void addedge(int u,int v,int f)
	{
		cnt++;
		e[cnt].v=v,e[cnt].f=f;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		swap(u,v);
		addedge(u,v,w);
		addedge(v,u,0);
	}
	int dep[N],q[N];
	int bfs()
	{
		for(int i=1;i<=n;i++)
			dep[i]=-1,cur[i]=head[i];
		dep[s]=0;
		int l=0,r=1;
		q[0]=s;
		while(l<r)
		{
			int u=q[l++];
			for(int i=head[u];i;i=e[i].nxt)
			{
				if(dep[e[i].v]==-1&&e[i].f>0)
				{
					dep[e[i].v]=dep[u]+1;
					q[r++]=e[i].v;
				}
			}
		}
		return dep[t]!=-1;
	}
	int dfs1(int u,int lim)
	{
		if(u==t||lim==0)
			return lim;
		int flow=0,f;
		for(int i=cur[u];i;i=e[i].nxt)
		{
			cur[u]=i;
			if(dep[e[i].v]==dep[u]+1&&(f=dfs1(e[i].v,min(lim,e[i].f))))
			{
				flow+=f;
				lim-=f;
				e[i].f-=f;
				e[(i-1^1)+1].f+=f;
				if(!lim)
					break;
			}
		}
		return flow;
	}
	void dinic()
	{
		while(bfs())
			mf+=dfs1(s,INF);
	}
	int dfs2(int u,int lim)
	{
		if(u==t||lim==0)
			return lim;
		vis[u]=1;
		int flow=0,f;
		for(int i=cur[u];i;i=e[i].nxt)
		{
			if(vis[e[i].v])
				continue;
			cur[u]=i;
			if(f=dfs2(e[i].v,min(lim,e[i].f)))
			{
				flow+=f;
				lim-=f;
				e[i].f-=f;
				e[(i-1^1)+1].f+=f;
				if(!lim)
					break;
			}
		}
		return flow;
	}
	void ff()
	{
		int x;
		for(int i=1;i<=n;i++)
			cur[i]=head[i],vis[i]=0;
		while(x=dfs2(s,INF))
		{
			for(int i=1;i<=n;i++)
				cur[i]=head[i],vis[i]=0;
			mf+=x;
		}
	}
}g;
const int N=20005;
int n,m,k,q,ku[N],kv[N],kw[N],a[N],h[N],t[N],lg[N],vis[N];
vector<pair<int,int>>e[N];
vector<int>od;
void dfs(int p,int s,flow f)
{
	if(p==k)
	{
		a[s]=f.mf;
		return;
	}
	flow r=f;
	r.add(ku[p],kv[p],30);
	r.ff();
	dfs(p+1,s,r);
	r=f;
	r.add(ku[p],kv[p],0);
	r.ff();
	dfs(p+1,s|(1<<p),r);
}
void dfs2(int u)
{
	vis[u]=1;
	for(auto &i:e[u])
	{
		int v=i.first,&w=i.second;
		if(w>=k)
		{
			od.push_back(w);
			w=-1;
		}
		if(!vis[v])
			dfs2(v);
	}
}
void reb()
{
	for(int i=0;i<m;i++)
		e[ku[i]].emplace_back(kv[i],i);
	dfs2(1);
	for(auto i:od)
		g.add(ku[i],kv[i],kw[i]);
	for(int u=1;u<=n;u++)
	{
		for(auto i:e[u])
		{
			int v=i.second;
			if(v>=k)
				g.add(ku[v],kv[v],kw[v]);
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	g.n=n,g.s=n,g.t=1;
	for(int i=0;i<k;i++)
		scanf("%d%d%*d",&ku[i],&kv[i]);
	for(int i=k;i<m;i++)
		scanf("%d%d%d",&ku[i],&kv[i],&kw[i]);
	reb();
	g.dinic();
	dfs(0,0,g);
	for(int i=0;i<k;i++)
		lg[1<<i]=i;
	while(q--)
	{
		for(int i=0;i<k;i++)
			scanf("%d",&h[i]);
		t[0]=0;
		for(int i=1;i<(1<<k);i++)
		{
			int l=i&(-i);
			t[i]=t[i^l]+h[lg[l]];
		}
		int ans=INT_MAX;
		for(int i=0;i<(1<<k);i++)
		{
			int s=a[i]+t[i];
			ans=min(ans,s);
		}
		printf("%d\n",ans);
	}
	return 0;
}