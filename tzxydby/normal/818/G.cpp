#include<bits/stdc++.h>
using namespace std;
struct flow
{
	static const int N=3000005,INF=1e9;
	int n,s,t;
	struct edge
	{
		int v,w,f,c,nxt;
	}e[N];
	int head[N],cur[N],cnt;
	void addedge(int u,int v,int w,int f,int c)
	{
		cnt++;
		e[cnt].v=v,e[cnt].w=w,e[cnt].f=f,e[cnt].c=c;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w,int c=0)
	{
		addedge(u,v,w,w,c);
		addedge(v,u,w,0,-c);
	}
	int h[N],dis[N],pre[N],pu[N];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	int min_cost(int f)
	{
		int res=0;
		for(int i=1;i<=cnt;i+=2)
			e[i].f=e[i].w;
		for(int i=2;i<=cnt;i+=2)
			e[i].f=0;
		while(f>0)
		{
			for(int i=1;i<=n;i++)
				dis[i]=INF;
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
			if(dis[t]==INF)
				return -1;
			for(int i=1;i<=n;i++)
				h[i]+=dis[i];
			int d=f;
			for(int u=t;u!=s;u=pu[u])
				d=min(d,e[pre[u]].f);
			f-=d;
			res+=d*h[t];
			for(int u=t;u!=s;u=pu[u])
			{
				e[pre[u]].f-=d;
				e[(pre[u]-1^1)+1].f+=d;
			}
		}
		return res;
	}
}g;
const int N=3005;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	g.n=n*2+2,g.s=n*2+1,g.t=n*2+2;
	for(int i=1;i<=n;i++)
	{
		g.add(g.s,i*2-1,1,0);
		g.add(i*2,g.t,1,0);
		g.add(i*2-1,i*2,1,-1);
		int s1=0,s2=0,s3=0;
		for(int j=i+1;j<=n;j++)
		{
			if(s1<4&&a[i]%7==a[j]%7)
			{
				s1++;
				g.add(i*2,j*2-1,1,0);
			}
			if(s2<4&&a[i]-a[j]==1)
			{
				s2++;
				g.add(i*2,j*2-1,1,0);
			}
			if(s3<4&&a[i]-a[j]==-1)
			{
				s3++;
				g.add(i*2,j*2-1,1,0);
			}
		}
	}
	printf("%d\n",-g.min_cost(4));
	return 0;
}