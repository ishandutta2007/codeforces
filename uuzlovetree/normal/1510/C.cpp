#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int T,n,m;
vector<int> g[maxn];
struct Edge
{
	int u,v;
	Edge(int u=0,int v=0):u(u),v(v){}
};
void addedge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}
int pre[maxn],dfs_clock,d[maxn],bcc_cnt;
stack<Edge> S;
vector<Edge> tmp;
map< pair<int,int>,int > ban;
pair<int,int> edg[maxn];
int cnt;
int tarjan(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for(int v:g[u])
	{
		Edge e=Edge(u,v);
		if(!pre[v])
		{
			S.push(e);
			child++;
			int lowv=tarjan(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u])
			{
				++bcc_cnt;
				tmp.clear();
				for(;;)
				{
					Edge x=S.top();S.pop();
					tmp.push_back(x);
					if(x.u==u&&x.v==v)break;
				}
				if(tmp.size()>1)
				{
					for(Edge x:tmp)
					{
						ban[make_pair(x.u,x.v)]=1;
					}
				}
			}
		}
		else if(pre[v]<pre[u]&&v!=fa)
		{
			S.push(e);
			lowu=min(lowu,pre[v]);
		}
	}
	return lowu;
}
int col[maxn];
void clear()
{
	ban.clear();
	cnt=0;bcc_cnt=0;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<=n;++i)pre[i]=0,col[i]=0;
	dfs_clock=0;
}
int dfs1(int u,int fa)
{
	int tot=0;
	pre[u]=1;
	for(int v:g[u])if(v!=fa)
	{
		tot+=dfs1(v,u);
	}
	int id=0;
	for(int v:g[u])if(v!=fa)
	{
		if(!col[v])id=v;
	}
	if(id)
	{
		col[u]=1;
		ban[make_pair(u,id)]=1;
		tot++;
	}
	return tot;
}
vector< pair<int,int> > Ans;
int dfs2(int u,int fa)
{
	pre[u]=1;
	int y=0;
	for(int v:g[u])if(v!=fa)
	{
		int x=dfs2(v,u);
		if(y&&x)
		{
			Ans.push_back(make_pair(x,y));
			y=0;
		}
		else if(x)y=x;
	}
	if(d[u]&1)
	{
		int x=u;
		if(y&&x)
		{
			Ans.push_back(make_pair(x,y));
			y=0;
		}
		else if(x)y=x;
	}
	return y;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)break;
		clear();
		for(int i=1;i<=m;++i)
		{
			int k,x,y;
			scanf("%d",&k);
			scanf("%d",&x);
			for(int j=2;j<=k;++j)
			{
				scanf("%d",&y);
				edg[++cnt]=make_pair(x,y);
				addedge(x,y);
				x=y;
			}
		}
		tarjan(1,0);
		for(int i=1;i<=n;++i)g[i].clear(),pre[i]=0,d[i]=0;
		for(int i=1;i<=cnt;++i)
		{
			int u=edg[i].first,v=edg[i].second;
			if(ban.count(make_pair(u,v))||ban.count(make_pair(v,u)))continue;
			d[u]++;d[v]++;
		}
		for(int i=1;i<=cnt;++i)
		{
			int u=edg[i].first,v=edg[i].second;
			if(ban.count(make_pair(u,v))||ban.count(make_pair(v,u)))continue;
			if((d[u]&1)&&(d[v]&1))addedge(u,v);
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(d[i]&1)ans++;
		ans/=2;
		for(int i=1;i<=n;++i)if(!pre[i])ans-=dfs1(i,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)g[i].clear(),pre[i]=0,d[i]=0;
		for(int i=1;i<=cnt;++i)
		{
			int u=edg[i].first,v=edg[i].second;
			if(ban.count(make_pair(u,v))||ban.count(make_pair(v,u)))continue;
			d[u]++;d[v]++;
		}
		for(int i=1;i<=cnt;++i)
		{
			int u=edg[i].first,v=edg[i].second;
			if(ban.count(make_pair(u,v))||ban.count(make_pair(v,u)))continue;
			addedge(u,v);
		}
		Ans.clear();
		for(int i=1;i<=n;++i)if(!pre[i])dfs2(i,0);
		for(auto p:Ans)printf("%d %d\n",p.first,p.second);
	}
}