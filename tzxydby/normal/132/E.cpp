#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=3000005,inf=1e9;
	int n,s,t;
	struct edge
	{
		int v,w,f,c,nxt;
	}e[N];
	int head[N],cnt;
	void init()
	{
		for(int i=0;i<=n;i++)
			head[i]=h[i]=0;
		cnt=0;
	}
	void addedge(int u,int v,int w,int f,int c)
	{
		cnt++;
		e[cnt].v=v,e[cnt].w=w,e[cnt].f=f,e[cnt].c=c;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	int add(int u,int v,int w,int c=0)
	{
		int p=cnt+1;
		addedge(u,v,w,w,c);
		addedge(v,u,w,0,-c);
		return p;
	}
	int h[N],dis[N],pre[N],pu[N];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pair<int,int> min_cost()
	{
		int a1=0,a2=0;
		for(int i=1;i<=cnt;i+=2)
			e[i].f=e[i].w;
		for(int i=2;i<=cnt;i+=2)
			e[i].f=0;
		while(1)
		{
			for(int i=1;i<=n;i++)
				dis[i]=inf;
			dis[s]=0;
			pq.emplace(0,s);
			while(!pq.empty())
			{
				auto p=pq.top();
				pq.pop();
				int u=p.second;
				if(dis[u]<p.first)
					continue;
				for(int i=head[u];i;i=e[i].nxt)
				{
					int v=e[i].v,c=e[i].c,f=e[i].f;
					if(f>0&&dis[v]>dis[u]+c+h[u]-h[v])
					{
						dis[v]=dis[u]+c+h[u]-h[v];
						pre[v]=i,pu[v]=u;
						pq.emplace(dis[v],v);
					}
				}
			}
			if(dis[t]==inf)
				return {a1,a2};
			for(int i=1;i<=n;i++)
				h[i]+=dis[i];
			int d=INT_MAX;
			for(int u=t;u!=s;u=pu[u])
				d=min(d,e[pre[u]].f);
			a1+=d;
			a2+=d*h[t];
			for(int u=t;u!=s;u=pu[u])
			{
				e[pre[u]].f-=d;
				e[((pre[u]-1)^1)+1].f+=d;
			}
		}
	}
}g;
const int N=300;
int n,m,a[N],d[N][N],p[N],v[N];
vector<int>a1,a2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	g.n=n*2+m+4,g.s=g.n-1,g.t=g.n;
	int s=g.n-3,t=g.n-2;
	g.init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			d[i][j]=g.add(n+j,i,1,(a[i]==a[j]?0:__builtin_popcount(a[i])));
		for(int j=1;j<=m;j++)
			d[i][n+j]=g.add(n+n+j,i,1,__builtin_popcount(a[i]));
		g.add(g.s,i+n,1,0);
		g.add(i,g.t,1,0);
		g.add(n+i,t,1,0);
	}
	for(int j=1;j<=m;j++)
		g.add(s,n+n+j,1,0);
	g.add(t,s,g.inf,0);
	int ans=g.min_cost().second;
	for(int j=1;j<=m;j++)
		v[j]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(!g.e[d[i][j]].f)
				p[i]=p[j];
		for(int j=1;j<=m;j++)
			if(!g.e[d[i][n+j]].f)
				p[i]=j;
		if(v[p[i]]!=a[i])
			a1.push_back(p[i]),a2.push_back(a[i]);
		v[p[i]]=a[i];
		a1.push_back(p[i]),a2.push_back(-1);
	}
	printf("%d %d\n",a1.size(),ans);
	for(int i=0;i<a1.size();i++)
	{
		if(a2[i]==-1)
			printf("print(%c)\n",'a'+a1[i]-1);
		else
			printf("%c=%d\n",'a'+a1[i]-1,a2[i]);
	}
	return 0;
}