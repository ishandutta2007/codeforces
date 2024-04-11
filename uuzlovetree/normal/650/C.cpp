#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define maxn 1000005
using namespace std;
int n,m;
vector<vector<int>> a;
vector<pii> b;
struct edge
{
	int to,next,w;
}e[maxn<<2];
int head[maxn<<1],p;
void addedge(int u,int v,int w)
{
	e[++p].to=v;e[p].w=w;e[p].next=head[u];head[u]=p;
}
int id(int x,int y)
{
	return (x-1)*m+y;
}
int cnt;
bool vis[maxn];
int dis[maxn<<1],d[maxn<<1];
vector<int> s[maxn<<1];
int belong[maxn];
void dfs(int u,int x)
{
	s[x].push_back(u);
	for(int i=head[u];i;i=e[i].next)if(!e[i].w)
	{
		int v=e[i].to;
		if(!vis[v])vis[v]=1,dfs(v,x);
	}
}
void toposort()
{
	queue<int> q;
	for(int i=1;i<=p;++i)if(e[i].w!=-1)d[e[i].to]++;
	for(int i=1;i<=cnt;++i)if(!d[i])q.push(i),dis[i]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].next)if(e[i].w!=-1)
		{
			int v=e[i].to;
			dis[v]=max(dis[v],dis[u]+e[i].w);
			d[v]--;
			if(!d[v])q.push(v);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	cnt=n*m;
	vector<int> T;
	T.clear();a.push_back(T);
	for(int i=1;i<=n;++i)
	{
		T.clear();
		T.push_back(0);
		for(int j=1;j<=m;++j)
		{
			int x;scanf("%d",&x);
			T.push_back(x);
		}
		a.push_back(T);
	}
	for(int i=1;i<=n;++i)
	{
		b.clear();
		for(int j=1;j<=m;++j)b.push_back(mp(a[i][j],j));
		sort(b.begin(),b.end());
		for(int j=1;j<b.size();++j)
		{
			int u=id(i,b[j].second),v=id(i,b[j-1].second);
			if(b[j].first==b[j-1].first)addedge(v,u,0),addedge(u,v,0);
			else addedge(v,u,1);
		}
	}
	for(int j=1;j<=m;++j)
	{
		b.clear();
		for(int i=1;i<=n;++i)b.push_back(mp(a[i][j],i));
		sort(b.begin(),b.end());
		for(int i=1;i<b.size();++i)
		{
			int u=id(b[i].second,j),v=id(b[i-1].second,j);
			if(b[i].first==b[i-1].first)addedge(v,u,0),addedge(u,v,0);
			else addedge(v,u,1);
		}
	}
	for(int i=1;i<=n*m;++i)if(!vis[i])
	{
		dfs(i,++cnt);
		for(int j=0;j<s[cnt].size();++j)
		{
			int u=s[cnt][j];
			belong[u]=cnt;
		}
	}
	p=0;
	memset(head,0,sizeof(head));
	for(int i=1;i<=n;++i)
	{
		b.clear();
		for(int j=1;j<=m;++j)b.push_back(mp(a[i][j],j));
		sort(b.begin(),b.end());
		for(int j=1;j<b.size();++j)
		{
			int u=id(i,b[j].second),v=id(i,b[j-1].second);
			u=belong[u],v=belong[v];
			if(b[j].first!=b[j-1].first)addedge(v,u,1);
		}
	}
	for(int j=1;j<=m;++j)
	{
		b.clear();
		for(int i=1;i<=n;++i)b.push_back(mp(a[i][j],i));
		sort(b.begin(),b.end());
		for(int i=1;i<b.size();++i)
		{
			int u=id(b[i].second,j),v=id(b[i-1].second,j);
			u=belong[u];v=belong[v];
			if(b[i].first!=b[i-1].first)addedge(v,u,1);
		}
	}
	toposort();
	for(int i=n*m+1;i<=cnt;++i)
	{
		for(int j=0;j<s[i].size();++j)
		{
			int u=s[i][j];
			dis[u]=dis[i];
		}
	}
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)printf("%d ",dis[++tot]);
		puts("");
	}
	return 0;
}