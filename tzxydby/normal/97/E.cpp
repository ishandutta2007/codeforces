#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,q,fa[N],f[N][17],dep[N],s[N],a[N];
vector<int>e[N];
int get(int u){return u==fa[u]?u:fa[u]=get(fa[u]);}
void dfs1(int u)
{
	dep[u]=dep[f[u][0]]+1;
	for(auto v:e[u])
	{
		if(!dep[v])
		{
			f[v][0]=u;
			dfs1(v);
			if(get(u)==get(v))
				a[u]|=a[v];
		}
		else if(dep[v]+1<dep[u])
		{
			if((dep[u]+dep[v]+1)&1)
				a[u]=1;
			for(int x=get(u);dep[x]>dep[v]+1;x=get(x))
				fa[x]=f[x][0];
		}
	}
}
void dfs2(int u)
{
	s[u]+=a[u];
	for(auto v:e[u])
	{
		if(dep[v]==dep[u]+1)
		{
			if(get(u)==get(v))
				a[v]|=a[u];
			s[v]=s[u];
			dfs2(v);
		}
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=16;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=16;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		if(!dep[i])
			dfs1(i),dfs2(i);
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	scanf("%d",&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int l=lca(u,v);
		if(!l)
			puts("No");
		else if(((dep[u]+dep[v])&1)||s[u]+s[v]-2*s[l])
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}