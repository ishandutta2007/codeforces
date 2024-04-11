#include<bits/stdc++.h>
using namespace std;
struct Dinic
{
	static const int N=5005,M=50005;
	int n,s,t;
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
			mf+=dfs(s,1e9);
		return mf;
	}
}g;
const int N=105;
int a[N],n,m,cnt=2,p[400005];
map<int,int>mp[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i];
		if(i&1)
		{
			for(int j=2;j<=40000;j++)
			{
				if(x%j)
					continue;
				mp[i][j]=++cnt;
				int k=0;
				while(x%j==0)
				{
					x/=j;
					k++;
				}
				g.add(1,cnt,k);
			}
			if(x!=1)
			{
				mp[i][x]=++cnt;
				g.add(1,cnt,1);
			}
		}
		else
		{
			for(int j=2;j<=40000;j++)
			{
				if(x%j)
					continue;
				mp[i][j]=++cnt;
				int k=0;
				while(x%j==0)
				{
					x/=j;
					k++;
				}
				g.add(cnt,2,k);
			}
			if(x!=1)
			{
				mp[i][x]=++cnt;
				g.add(cnt,2,1);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y&1)
			swap(x,y);
		int gcd=__gcd(a[x],a[y]);
		for(int j=1;j*j<=gcd;j++)
		{
			if(gcd%j)
				continue;
			g.add(mp[x][j],mp[y][j],50);
			if(j*j==gcd)
				continue;
			g.add(mp[x][gcd/j],mp[y][gcd/j],50);
		}
	}
	g.n=cnt,g.s=1,g.t=2;
	printf("%d\n",g.max_flow());
	return 0;
}