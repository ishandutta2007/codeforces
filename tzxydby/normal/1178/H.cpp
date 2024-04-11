#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,dl[N],dr[N],fl[N],fr[N],od[N];
long long a[N],b[N];
struct nd
{
	long long x,y;
	int z;
};
bool operator<(nd a,nd b)
{
	return make_pair(make_pair(a.x,-a.y),a.z)<make_pair(make_pair(b.x,-b.y),b.z);
}
vector<nd>sq;
vector<long long>pl,pr;
int chk(long long t)
{
	sq.clear(),pl.clear(),pr.clear();
	for(int i=1;i<=n+n;i++)
		sq.push_back({b[i],a[i]*t+b[i],(i<=n)});
	sort(sq.begin(),sq.end());
	long long mx=0;
	for(auto i:sq)
	{
		long long x=i.x,y=i.y,z=i.z;
		mx=max(mx,y);
		if(z)
			pl.push_back(mx);
		else
			pr.push_back(y);
	}
	sort(pl.begin(),pl.end());
	sort(pr.begin(),pr.end());
	for(int i=0;i<n;i++)
		if(pl[i]<pr[i])
			return 0;
	return 1;
}
struct flow
{
	static const int N=100005,inf=1e9;
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
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n+n;i++)
		cin>>a[i]>>b[i];
	long long l=-1,r=1e9+100;
	while(r-l>1)
	{
		long long md=l+r>>1;
		if(chk(md))
			r=md;
		else
			l=md;
	}
	if(!chk(r))
		cout<<"-1\n";
	else
	{
		for(int i=1;i<=n+n;i++)
			dl[i]=++m;
		for(int i=1;i<=n+n;i++)
			dr[i]=++m;
		for(int i=1;i<=n+n;i++)
			fl[i]=++m;
		for(int i=1;i<=n+n;i++)
			fr[i]=++m;
		g.n=m+2,g.s=m+1,g.t=m+2;
		g.init();
		for(int i=1;i<=n+n;i++)
			od[i]=i;
		sort(od+1,od+n+n+1,[&](int i,int j){return b[i]==b[j]?i<j:b[i]>b[j];});
		for(int i=1;i<=n+n;i++)
		{
			int u=od[i];
			if(u<=n)
				g.add(g.s,dl[u],1,0);
			g.add(dl[u],fl[i],g.inf,1);
			g.add(fl[i],dl[u],g.inf,0);
		}
		for(int i=1;i<n+n;i++)
			g.add(fl[i],fl[i+1],g.inf,0);
		for(int i=1;i<=n+n;i++)
			od[i]=i;
		sort(od+1,od+n+n+1,[&](int i,int j){return a[i]*r+b[i]==a[j]*r+b[j]?i<j:a[i]*r+b[i]>a[j]*r+b[j];});
		for(int i=1;i<=n+n;i++)
		{
			int u=od[i];
			if(u>n)
				g.add(dr[u],g.t,1,0);
			g.add(dr[u],fr[i],g.inf,1);
			g.add(fr[i],dr[u],g.inf,0);
		}
		for(int i=1;i<n+n;i++)
			g.add(fr[i],fr[i+1],g.inf,0);
		for(int i=1;i<=n+n;i++)
			g.add(dl[i],dr[i],g.inf,0);
		int ans=g.min_cost().second;
		cout<<r<<" "<<ans<<"\n";
	}
	return 0;
}