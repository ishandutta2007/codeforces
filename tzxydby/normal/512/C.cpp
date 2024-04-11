#include<bits/stdc++.h>
using namespace std;
struct Dinic
{
	static const int N=205,M=50005;
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
const int N=205,M=20005;
int a[N],n,p[M],vis[N];
vector<int>e[N],ans;
vector<vector<int>>k;
void dfs(int u)
{
	ans.push_back(u);
	vis[u]=1;
	for(auto v:e[u])
		if(!vis[v])
			dfs(v);
}
int main()
{
	for(int i=2;i<=20000;i++)
		if(!p[i])
			for(int j=i+i;j<=20000;j+=i)
				p[j]=1;
	scanf("%d",&n);
	g.n=n+2,g.s=n+1,g.t=n+2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)
		{
			g.add(i,n+2,2);
			continue;
		}
		g.add(n+1,i,2);
		for(int j=1;j<=n;j++)
			if(a[j]&1)
				if(!p[a[i]+a[j]])
					g.add(i,j,1);
	}
	if(g.max_flow()!=n)
	{
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)
			continue;
		for(int j=g.head[i];j;j=g.e[j].nxt)
		{
			if(g.e[j].v<=n&&g.e[j].w!=g.e[j].f)
			{
				e[i].push_back(g.e[j].v);
				e[g.e[j].v].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans.clear();
			dfs(i);
			k.push_back(ans);
		}
	}
	printf("%d\n",k.size());
	for(auto i:k)
	{
		printf("%d ",i.size());
		for(auto j:i)
			printf("%d ",j);
		puts("");
	}
	return 0;
}