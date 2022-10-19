#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,q,ru[N],rv[N],vis[N],fa[N],fd[N],dep[N],w[N],s;
vector<int>e[N],a1[N],a2[N];
void dfs1(int u)
{
	vis[u]=1;
	for(auto i:e[u])
	{
		int v=u^ru[i]^rv[i];
		if(!vis[v])
		{
			dep[v]=dep[u]+1;
			fa[v]=u;
			fd[v]=i;
			dfs1(v);
		}
	}
}
void dfs2(int u,int h)
{
	for(auto i:e[u])
	{
		int v=u^ru[i]^rv[i];
		if(fa[v]!=u)
			continue;
		if(w[fd[v]])
		{
			if(h)
			{
				h=0;
				dfs2(v,1);
			}
			else
			{
				s++;
				h=1;
				dfs2(v,1);
			}
		}
		else
			dfs2(v,0);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&ru[i],&rv[i]);
		e[ru[i]].push_back(i);
		e[rv[i]].push_back(i);
	}
	dfs1(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		while(u!=v)
		{
			if(dep[u]>dep[v])
			{
				a1[i].push_back(u);
				w[fd[u]]^=1;
				u=fa[u];
			}
			else
			{
				a2[i].push_back(v);
				w[fd[v]]^=1;
				v=fa[v];
			}
		}
		a1[i].push_back(u);
	}
	int fl=1;
	for(int i=1;i<=m;i++)
		if(w[i])
			fl=0;
	if(fl)
	{
		puts("YES");
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",a1[i].size()+a2[i].size());
			for(int j=0;j<a1[i].size();j++)
				printf("%d ",a1[i][j]);
			for(int j=(int)a2[i].size()-1;j>=0;j--)
				printf("%d ",a2[i][j]);
			puts("");
		}
	}
	else
	{
		puts("NO");
		dfs2(1,0);
		printf("%d\n",s);
	}
	return 0;
}