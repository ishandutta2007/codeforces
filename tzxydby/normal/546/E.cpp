#include<bits/stdc++.h>
using namespace std;
struct Dinic
{
	static const int N=205,M=2005;
	int n,m,s,t;
	struct edge
	{
		int v,w,f,nxt;
	}e[M];
	int head[N],cur[N],cnt;
	void addedge(int u,int v,int w,int f)
	{
		cnt++;
		e[cnt].v=v,e[cnt].w=w,e[cnt].f=f;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		addedge(u,v,w,w);
		addedge(v,u,w,0);
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
		for(int i=head[u];i;i=e[i].nxt)
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
			mf+=dfs(s,1e9);
		return mf;
	}
}g;
const int N=205;
int a[N],b[N],ans[N][N],n,m,sa,sum;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	g.n=2*n+2,g.s=2*n+1,g.t=2*n+2;
	for(int i=1;i<=n;i++)
	{
		sa+=a[i];
		sum+=b[i];
		g.add(2*n+1,i,a[i]);
		g.add(i+n,2*n+2,b[i]);
		g.add(i,i+n,1e8);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g.add(u,v+n,1e8);
		g.add(v,u+n,1e8);
	}
	if(sa!=sum||sum!=g.max_flow())
		puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			for(int j=g.head[i];j;j=g.e[j].nxt)
			{
				int v=g.e[j].v-n;
				if(v>n)
					continue;
				ans[i][v]+=g.e[j].w-g.e[j].f;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d ",ans[i][j]);
			puts("");
		}
	}
	return 0;
}