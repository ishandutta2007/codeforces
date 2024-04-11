#include<bits/stdc++.h>
using namespace std;
struct Dinic
{
	static const int N=20005,M=200005;
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
const int N=10005;
pair<int,int>a[N];
int n,m,q;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	q++;
	a[q]=make_pair(m,n);
	sort(a+1,a+q+1);
	g.n=7+q,g.s=6,g.t=7;
	for(int i=1;i<=q;i++)
	{
		int l=a[i-1].first+1,r=a[i].first,s=a[i].second-a[i-1].second;
		if(l>r)
			continue;
		if(s<0)
		{
			puts("unfair");
			return 0;
		}
		g.add(6,7+i,s);
		for(int j=1;j<=5;j++)
		{
			int num1=a[i].first/5+(a[i].first%5>=j);
			int num2=a[i-1].first/5+(a[i-1].first%5>=j);
			g.add(7+i,j,num1-num2);
		}
	}
	for(int j=1;j<=5;j++)
		g.add(j,7,n/5);
	if(g.max_flow()==n)
		puts("fair");
	else
		puts("unfair");
	return 0;
}