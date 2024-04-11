#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,md,dep[N],vis[N],fa[N];
vector<int>e[N],a[N],a1,a2;
void dfs(int u)
{
	vis[u]=1,md=max(md,dep[u]);
	a[dep[u]].push_back(u);
	for(auto v:e[u])
	{
		if(!vis[v])
		{
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
	}
}
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		dep[i]=vis[i]=fa[i]=0;
		e[i].clear();
		a[i].clear();
	}
	md=0,dep[1]=1;
	a1.clear(),a2.clear();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	if(md>=(n+1)/2)
	{
		puts("PATH");
		printf("%d\n",md);
		int u=a[md][0];
		for(int i=1;i<=md;i++)
		{
			printf("%d ",u);
			u=fa[u];
		}
		puts("");
	}
	else
	{
		puts("PAIRING");
		for(int i=1;i<=md;i++)
			for(int j=0;j+1<a[i].size();j+=2)
				a1.push_back(a[i][j]),a2.push_back(a[i][j+1]);
		printf("%d\n",a1.size());
		for(int i=0;i<a1.size();i++)
			printf("%d %d\n",a1[i],a2[i]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}