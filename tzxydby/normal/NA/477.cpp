#include<bits/stdc++.h>
using namespace std;struct flow
{
	static const int N=500005,INF=1e9;
	int n,s,t;
	struct edge
	{
		int v,f,nxt;
	}e[N];
	int head[N],cur[N],cnt;
	void addedge(int u,int v,int f)
	{
		cnt++;
		e[cnt].v=v,e[cnt].f=f;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		addedge(u,v,w);
		addedge(v,u,0);
	}
	void init()
	{
		cnt=0;
		for(int i=1;i<=n;i++)
			head[i]=0;
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
	int dfs(int u,int lim)
	{
		if(u==t||lim==0)
			return lim;
		int flow=0,f;
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
	int max_flow()
	{
		int mf=0;
		while(bfs())
			mf+=dfs(s,INF);
		return mf;
	}
}g;
const int N=100005;
int n,m,f;
struct edge
{
	int u,v,d;
	bool operator<(const edge k)const
	{
		return d<k.d;
	}
}e[N];
int check(int x)
{
	g.init();
	for(int i=1;i<=n;i++)
	{
		g.add(g.s,i,1);
		g.add(n+i,g.t,1);
	}
	for(int i=1;i<=x;i++)
		g.add(e[i].u,n+e[i].v,1);
	if(g.max_flow()==n)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
	sort(e+1,e+m+1);
	g.n=n+n+2,g.s=n+n+1,g.t=n+n+2;
	int l=n-1,r=m;
	while(r-l>1)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	if(r==m&&!check(r))
		puts("-1");
	else
		printf("%d\n",e[r].d);
	return 0;
}