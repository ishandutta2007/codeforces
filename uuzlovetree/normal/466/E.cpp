#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
struct Opt
{
	int op,x,y;
	Opt(int OP=0,int X=0,int Y=0):op(OP),x(X),y(Y){}
}opt[maxn];
vector< pair<int,int> > qry[maxn];
int Ans[maxn];
int m1,m2;
int fa[maxn];
int find(int x){if(fa[x]==x)return x;else return fa[x]=find(fa[x]);}
vector<int> g[maxn];
bool isroot[maxn];
int anc[maxn][20],d[maxn];
void dfs(int u)
{
	for(int v:g[u])
	{
		d[v]=d[u]+1;anc[v][0]=u;
		dfs(v);
	}
}
int LCA(int u,int v)
{
	if(d[u]<=d[v])swap(u,v);
	for(int i=18;i>=0;--i)if(d[anc[u][i]]>=d[v])u=anc[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,isroot[i]=1;
	for(int i=1;i<=m;++i)
	{
		int t,x,y;
		scanf("%d%d",&t,&x);
		if(t!=2)scanf("%d",&y);
		if(t==1)opt[++m1]=Opt(t,x,y),g[y].push_back(x),isroot[x]=0;
		if(t==2)opt[++m1]=Opt(t,x);
		if(t==3)qry[y].push_back(make_pair(x,++m2));
	}
	for(int i=1;i<=n;++i)if(isroot[i])g[0].push_back(i);
	dfs(0);
	for(int j=1;j<=18;++j)
		for(int i=1;i<=n;++i)anc[i][j]=anc[anc[i][j-1]][j-1];
	int id=0;
	for(int i=1;i<=m1;++i)
	{
		int t,x,y;
		t=opt[i].op,x=opt[i].x,y=opt[i].y;
		if(t==1)
		{
			if(find(x)!=find(y))fa[find(x)]=find(y);
		}
		if(t==2)
		{
			++id;
			for(auto pa:qry[id])
			{
				int u=x,v=pa.first;
				if(LCA(u,v)==v&&find(u)==find(v))Ans[pa.second]=1;
				else Ans[pa.second]=0;
			}
		}
	}
	for(int i=1;i<=m2;++i)if(Ans[i])puts("YES");else puts("NO");
}