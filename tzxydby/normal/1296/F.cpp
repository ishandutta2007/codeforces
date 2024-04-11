#include<bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int>e[N],p;
int n,m,fa[N],val[N],a[N],b[N];
struct X
{
	int a,b,g;
	bool operator<(const X k)const
	{
		return g<k.g;
	}
}v[N];
void dfs(int u,int f)
{
	fa[u]=f;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
void up(int u,int v,int g)
{
	if(fa[u]==v)
		val[u]=g;
	else
		val[v]=g;
}
int down(int u,int v)
{
	if(fa[u]==v)
		return val[u];
	else
		return val[v];
}
int path(int u,int f,int zh,int g)
{
	if(u==zh)
		return 1;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		if(path(v,u,zh,g))
		{
			up(u,v,g);
			return 1;
		}
	}
	return 0;
}
pair<int,int> check(int u,int f,int zh)
{
	if(u==zh)
		return make_pair(1,1e9);
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		auto x=check(v,u,zh);
		if(x.first==1)
		{
			x.second=min(x.second,down(u,v));
			return x;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[i]=u,b[i]=v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].g);
	sort(v+1,v+m+1);
	for(int i=1;i<=m;i++)
		path(v[i].a,0,v[i].b,v[i].g);
	for(int i=1;i<=m;i++)
	{
		if(check(v[i].a,0,v[i].b).second!=v[i].g)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",max(down(a[i],b[i]),1));
	return 0;
}