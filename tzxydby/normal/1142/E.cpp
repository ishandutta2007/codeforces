#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,vis[N],in[N],d[N];
vector<int>e[N],g[N],s;
int ask(int u,int v){printf("? %d %d\n",u,v);fflush(stdout);int x;scanf("%d",&x);return x;}
void dfs(int u)
{
	vis[u]=in[u]=1;
	for(auto v:e[u])
	{
		if(!in[v])
			g[u].push_back(v),d[v]++;
		if(!vis[v])
			dfs(v);
	}
	in[u]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		if(!d[i])
			s.push_back(i);
	while(s.size()>1)
	{
		int u=s.back();
		s.pop_back();
		int v=s.back();
		s.pop_back();
		if(!ask(u,v))
			swap(u,v);
		s.push_back(u);
		for(auto w:g[v])
			if(!--d[w])
				s.push_back(w);
	}
	printf("! %d\n",s[0]);
	return 0;
}