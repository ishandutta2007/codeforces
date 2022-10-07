#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,q,edgenum=1,head[200005],dfn[200005],low[200005],in[200005],scc;
int pa[200005],dep[200005],sze[200005],son[200005],top[200005],c1[200005],c2[200005];
int st[200005],t;
vector<int>SCC[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind;
void Tarjan(int node,int pre)
{
	if(dfn[node])return;
	dfn[node]=low[node]=++ind;
	st[++t]=node;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(!dfn[to])
		{
			Tarjan(to,hd);
			low[node]=min(low[node],low[to]);
		}
		else if(hd!=pre&&(hd^1)!=pre)
		{
			low[node]=min(low[node],dfn[to]);
		}
	}
	if(low[node]==dfn[node])
	{
		int v=st[t--];
		in[v]=++scc;
		SCC[scc].push_back(v);
		while(v!=node)
		{
			v=st[t--];
			in[v]=scc;
			SCC[scc].push_back(v);
		}
	}
}
void dfs1(int node)
{
	dep[node]=dep[pa[node]]+1;
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		sze[node]+=sze[to];
		if(sze[to]>sze[son[node]])son[node]=to;
	}
}
void dfs2(int node,int t)
{
	dfn[++ind]=node;
	top[node]=t;
	if(son[node])dfs2(son[node],t);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		dfs2(to,to);
	}
}
int LCA(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=pa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	return v;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	  Tarjan(i,-1);
	int num=edgenum;
	edgenum=0;
	memset(head,0,sizeof(head));
	for(int i=2;i<=num;i+=2)
	{
		int u=e[i].to,v=e[i+1].to;
		if(in[u]!=in[v])
		{
			add(in[u],in[v]);
			add(in[v],in[u]);
		}
	}
	n=scc;
	ind=0;
	for(int i=1;i<=n;i++)
	{
		if(!pa[i])
		{
			dfs1(i);
			dfs2(i,i);
		}
	}
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u=in[u],v=in[v];
		int d=LCA(u,v);
		c1[u]++;
		c2[v]++;
		c1[d]--;
		c2[d]--;
	}
	for(int i=n;i>=1;i--)
	{
		if(c1[dfn[i]]&&c2[dfn[i]])
		{
			printf("No\n");
			return 0;
		}
		c1[pa[dfn[i]]]+=c1[dfn[i]];
		c2[pa[dfn[i]]]+=c2[dfn[i]];
	}
	printf("Yes\n");
	return 0;
}