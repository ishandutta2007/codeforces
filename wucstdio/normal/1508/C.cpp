#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#define ll long long
using namespace std;
int n,m,from[200005],tmp[200005],top,tot;
ll dis[200005];
map<pair<int,int>,ll>e;
set<int>r;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
queue<int>q2;
struct Tree
{
	struct Edge
	{
		int to;
		int nxt;
		ll len;
	}e[200005];
	int n,edgenum,head[100005],pa[100005],dep[100005];
	ll dis[100005];
	void add(int u,int v,ll l)
	{
		e[++edgenum].len=l;
		e[edgenum].to=v;
		e[edgenum].nxt=head[u];
		head[u]=edgenum;
	}
	void dfs(int node)
	{
		dep[node]=dep[pa[node]]+1;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(to==pa[node])continue;
			pa[to]=node;
			dis[to]=e[hd].len;
			dfs(to);
		}
	}
	ll calc(int u,int v)
	{
		ll ans=0;
		if(dep[u]<dep[v])swap(u,v);
		while(dep[u]>dep[v])
		{
			ans=max(ans,dis[u]);
			u=pa[u];
		}
		while(u!=v)
		{
			ans=max(ans,dis[u]);
			ans=max(ans,dis[v]);
			u=pa[u];
			v=pa[v];
		}
		return ans;
	}
}T;
int main()
{
	scanf("%d%d",&n,&m);
	ll xx=0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll l;
		scanf("%d%d%lld",&u,&v,&l);
		xx^=l;
		e[make_pair(u,v)]=e[make_pair(v,u)]=l;
	}
	for(int i=2;i<=n;i++)r.insert(i);
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q2.push(1);
	ll sum=0;
	while(!r.empty())
	{
		if(q2.empty())
		{
			while(!q.empty()&&dis[q.top().second]<q.top().first)q.pop();
			sum+=q.top().first;
			q2.push(q.top().second);
			r.erase(q.top().second);
			q.pop();
		}
		int node=q2.front();
		q2.pop();
		top=0;
		for(auto x:r)
		{
			ll&l=e[make_pair(node,x)];
			if(!l)
			{
				tot++;
				dis[x]=0;
				q2.push(x);
				tmp[++top]=x;
			}
			else
			{
				if(dis[x]>l)
				{
					dis[x]=l;
					q.push(make_pair(l,x));
				}
			}
		}
		while(top)r.erase(tmp[top--]);
	}
	if(tot!=1ll*n*(n-1)/2-m)
	{
		printf("%lld\n",sum);
		return 0;
	}
	sum+=xx;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]!=-1&&(x==0||dis[j]<dis[x]))
			  x=j;
		}
		if(i!=1)
		{
			if(dis[x]==0)
			{
				T.add(from[x],x,xx);
				T.add(x,from[x],xx);
			}
			else
			{
				T.add(from[x],x,dis[x]);
				T.add(x,from[x],dis[x]);
			}
		}
		dis[x]=-1;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]==-1)continue;
			if(e[make_pair(x,j)]<dis[j])dis[j]=e[make_pair(x,j)],from[j]=x;
		}
	}
	T.dfs(1);
	ll ans=sum;
	for(auto ee:e)
	{
		int u=ee.first.first;
		int v=ee.first.second;
		ll l=ee.second;
		if(l)ans=min(ans,sum-T.calc(u,v)+l);
	}
	printf("%lld\n",ans);
	return 0;
}