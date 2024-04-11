#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,fb[N],sz[N],fa[N],m;
set<int>e[N];
void sol(int u,int f,int l)
{
	sz[u]=1,fa[u]=f;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		sol(v,u,l);
		sz[u]+=sz[v];
	}
	if(sz[u]==fb[l])
		m=u;
}
int dfs(int u,int l)
{
	if(l<=2)
		return 1;
	m=0;
	sol(u,0,l-1);
	if(m)
	{
		int x=fa[m];
		e[m].erase(x);
		e[x].erase(m);
		int a1=dfs(m,l-1),a2=dfs(x,l-2);
		return a1&&a2;
	}
	m=0;
	sol(u,0,l-2);
	if(m)
	{
		int x=fa[m];
		e[m].erase(x);
		e[x].erase(m);
		int a1=dfs(m,l-2),a2=dfs(x,l-1);
		return a1&&a2;
	}
	return 0;
}
int main()
{
	fb[1]=fb[2]=1;
	for(int i=3;i<=27;i++)
		fb[i]=fb[i-1]+fb[i-2];
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}
	int l=1;
	while(fb[l]<n)
		l++;
	if(fb[l]!=n)
	{
		puts("NO");
		return 0;
	}
	int f=dfs(1,l);
	puts(f?"YES":"NO");
	return 0;
}