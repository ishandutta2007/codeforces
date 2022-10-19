#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ru[N],rv[N],in[N],fa[N][20],dep[N],a[N],bg[N],ed[N],ti,ps[N];
vector<int>e[N];
struct dsu
{
	int f[N];
	void init(){for(int i=1;i<=n;i++)f[i]=i;}
	int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
	void mg(int u,int v){f[fa(u)]=fa(v);}
}d;
void dfs(int u,int f)
{
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	ti++;
	ps[ti]=u;
	bg[u]=ti;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
	ed[u]=ti;
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=18;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=18;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int jump(int u,int v)
{
	int c=dep[u]-dep[v]-1;
	for(int i=18;i>=0;i--)
		if(c>>i&1)
			u=fa[u][i];
	return u;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&ru[i],&rv[i]);
	d.init();
	for(int i=1;i<=m;i++)
	{
		if(d.fa(ru[i])!=d.fa(rv[i]))
		{
			in[i]=1;
			d.mg(ru[i],rv[i]);
			e[ru[i]].push_back(rv[i]);
			e[rv[i]].push_back(ru[i]);
		}
	}
	dfs(1,0);
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=m;i++)
	{
		if(!in[i])
		{
			int l=lca(ru[i],rv[i]);
			if(l==ru[i])
			{
				int p=jump(rv[i],ru[i]);
				a[bg[p]]++;
				a[ed[p]+1]--;
				a[bg[rv[i]]]--;
				a[ed[rv[i]]+1]++;
			}
			else if(l==rv[i])
			{
				int p=jump(ru[i],rv[i]);
				a[bg[p]]++;
				a[ed[p]+1]--;
				a[bg[ru[i]]]--;
				a[ed[ru[i]]+1]++;
			}
			else
			{
				a[1]++;
				a[bg[ru[i]]]--;
				a[ed[ru[i]]+1]++;
				a[bg[rv[i]]]--;
				a[ed[rv[i]]+1]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		printf("%d",(a[bg[i]]==0));
	return 0;
}