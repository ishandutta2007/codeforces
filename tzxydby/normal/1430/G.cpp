#include<bits/stdc++.h>
using namespace std;
const int N=105;
const long long inf1=10000000000,inf2=1000000000000000;
struct flow
{
	static const int N=3000005;
	static const long long INF=1000000000000000000;
	int n,s,t;
	struct edge
	{
		int v,nxt;
		long long f;
	}e[N];
	int head[N],cur[N],cnt,vis[N];
	void addedge(int u,int v,long long f)
	{
		cnt++;
		e[cnt].v=v,e[cnt].f=f;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,long long w)
	{
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
	long long dfs(int u,long long lim)
	{
		if(u==t||lim==0)
			return lim;
		long long flow=0,f;
		for(int i=cur[u];i;i=e[i].nxt)
		{
			cur[u]=i;
			if(dep[e[i].v]==dep[u]+1&&(f=dfs(e[i].v,min(lim,e[i].f))))
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
	long long max_flow()
	{
		long long mf=0;
		while(bfs())
			mf+=dfs(s,INF);
		return mf;
	}
	void sol(int u)
	{
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			long long f=e[i].f;
			if(f&&!vis[v])
				sol(v);
		}
	}
}g;
int n,m,a[N][N],t[N],u[N*N],v[N*N],w[N*N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		t[u[i]]+=w[i];
		t[v[i]]-=w[i];
	}
	g.n=n*(n+1)+2,g.s=g.n-1,g.t=g.n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
			a[i][j]=(i-1)*(n+1)+j;
		g.add(g.s,a[i][1],inf2);
		g.add(a[i][n+1],g.t,inf2);
		for(int j=1;j<=n;j++)
			g.add(a[i][j],a[i][j+1],j*t[i]+inf1);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			g.add(a[v[i]][j],a[u[i]][j+1],inf2);
	g.max_flow();
	g.sol(g.s);
	for(int i=1;i<=n;i++)
	{
		for(int j=n+1;;j--)
		{
			if(g.vis[a[i][j]])
			{
				cout<<j<<' ';
				break;
			}
		}
	}
	return 0;
}