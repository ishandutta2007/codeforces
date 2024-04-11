#include<bits/stdc++.h>
#define maxn 400005
using namespace std;
int n,m;
vector< pair<int,int> > g[maxn],Ans,g2[maxn];
vector<int> bcc[maxn];
int pre[maxn],low[maxn],Tim,cnt,isbri[maxn],bel[maxn];
stack<int> stk;
void tarjan(int u,int fid)
{
	pre[u]=low[u]=++Tim;
	stk.push(u);
	for(auto pa:g[u])
	{
		int v=pa.first,nid=pa.second;
		if(nid==fid)continue;
		if(!pre[v])
		{
			tarjan(v,nid);
			low[u]=min(low[u],low[v]);
			if(pre[u]<low[v])isbri[nid]=1;
			else
			{
				if(Ans[nid].first==v)swap(Ans[nid].first,Ans[nid].second);
			}
		}
		else
		{
			if(pre[v]<pre[u])low[u]=min(low[u],pre[v]);
			if(Ans[nid].first==u)swap(Ans[nid].first,Ans[nid].second);
		}
	}
	if(low[u]==pre[u])
	{
		++cnt;
		while(1)
		{
			int x=stk.top();stk.pop();
			bcc[cnt].push_back(x);
			bel[x]=cnt;
			if(x==u)break;
		}
	}
}
void dfs(int u,int fa)
{
	for(auto pa:g2[u])
	{
		int v=pa.first,nid=pa.second;
		if(v==fa)continue;
		if(bel[Ans[nid].first]==u)swap(Ans[nid].first,Ans[nid].second);
		dfs(v,u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	Ans.resize(m+2);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
		Ans[i]=make_pair(u,v);
	}
	Tim=0;
	tarjan(1,0);
	int rt=0;
	for(int i=1;i<=cnt;++i)if(bcc[i].size()>bcc[rt].size())rt=i;
	printf("%d\n",bcc[rt].size());
	for(int u=1;u<=n;++u)
	{
		for(auto pa:g[u])
		{
			int v=pa.first,nid=pa.second;
			if(isbri[nid])g2[bel[u]].push_back(make_pair(bel[v],nid));
		}
	}
	dfs(rt,0);
	for(int i=1;i<=m;++i)printf("%d %d\n",Ans[i].first,Ans[i].second);
}