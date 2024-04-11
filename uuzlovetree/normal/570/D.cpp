#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,m;
char s[maxn];
vector<int> g[maxn];
int sz[maxn],wson[maxn],d[maxn];
void dfs(int u)
{
	sz[u]=1;
	for(int v:g[u])
	{
		d[v]=d[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[wson[u]])wson[u]=v;
	}
}
int has[maxn][26];
vector<pair<int,int>> qry[maxn];
int Ans[maxn];
void add(int u,int x)
{
	has[d[u]][s[u]-'a']+=x;
	for(int v:g[u])add(v,x);
}
void solve(int u)
{
	has[d[u]][s[u]-'a']++;
	for(int v:g[u])if(v!=wson[u])
	{
		solve(v);
		add(v,-1);
	}
	if(wson[u])solve(wson[u]);
	for(int v:g[u])if(v!=wson[u])add(v,1);
	for(auto pa:qry[u])
	{
		int dep=pa.first,id=pa.second;
		int num=0;
		for(int j=0;j<26;++j)if(has[dep][j]&1)num++;
		if(num<=1)Ans[id]=1;else Ans[id]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int x,i=2;i<=n;++i)
	{
		scanf("%d",&x);
		g[x].push_back(i);
	}
	scanf("%s",s+1);
	for(int i=1;i<=m;++i)
	{
		int u,x;
		scanf("%d%d",&u,&x);
		qry[u].push_back(make_pair(x,i));
	}
	d[1]=1;dfs(1);
	solve(1);
	for(int i=1;i<=m;++i)if(Ans[i])puts("Yes");else puts("No");
}