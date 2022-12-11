#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
vector<int> g[maxn];
struct node
{
	int x,y,z;
	node(int X=0,int Y=0,int Z=0):x(X),y(Y),z(Z){} 
};
vector<int> q[maxn];
vector<node> ans;
bool vis[maxn];
void dfs(int u,int f)
{
	vis[u]=1;
	for(int v:g[u])if(v!=f)
	{
		if(vis[v])q[v].push_back(u);
		else dfs(v,u);
	}
	int sz=q[u].size();
	if(sz&1)
	{
		q[u].push_back(f);
		for(int i=0;i<sz;i+=2)ans.push_back(node(q[u][i],u,q[u][i+1]));
	}
	else
	{
		for(int i=0;i<sz;i+=2)ans.push_back(node(q[u][i],u,q[u][i+1]));
		q[f].push_back(u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(m&1)
	{
		puts("No solution");
	}
	else
	{
		dfs(1,0);
		for(int i=0;i<m/2;++i)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
	}
}