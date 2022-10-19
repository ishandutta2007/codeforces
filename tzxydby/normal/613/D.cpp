#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,q,fa[N][18],dep[N],dfn[N],c,a[N],st[N],t,fl[N],b[N],ans,xzh;
vector<int>e[N],g[N];
void dfs(int u,int f)
{
	fa[u][0]=f,dep[u]=dep[f]+1,dfn[u]=++c;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=17;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=17;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
bool cmp(const int &a,const int &b){return dfn[a]<dfn[b];}
void ins(int x)
{
	if(x==1)
		return;
	int l=lca(st[t],x);
	if(l==st[t])
	{
		st[++t]=x;
		return;
	}
	while(t>1&&dfn[st[t-1]]>=dfn[l])
	{
		g[st[t-1]].push_back(st[t]);
		t--;
	}
	if(l!=st[t])
	{
		g[l].push_back(st[t]);
		st[t]=l;
	}
	st[++t]=x;
}
void sol(int u,int zh)
{
	int s=0;
	for(auto v:g[u])
	{
		if(fa[v][0]==u&&b[u]==zh&&b[v]==zh)
			xzh=0;
		sol(v,zh);
		s+=fl[v];
	}
	if(b[u]==zh)
	{
		ans+=s;
		fl[u]=1;
	}
	else
	{
		if(s==0)
			fl[u]=0;
		else if(s==1)
			fl[u]=1;
		else
		{
			ans++;
			fl[u]=0;
		}
	}
	g[u].clear();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&q);
	for(int zh=1;zh<=q;zh++)
	{
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]=zh;
		}
		sort(a+1,a+m+1,cmp);
		st[t=1]=1,xzh=1,ans=0;
		for(int i=1;i<=m;i++)
			ins(a[i]);
		while(t>0)
		{
			g[st[t-1]].push_back(st[t]);
			t--;
		}
		sol(1,zh);
		printf("%d\n",xzh?ans:-1);
	}
	return 0;
}