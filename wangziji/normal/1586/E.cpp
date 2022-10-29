#include <bits/stdc++.h>
using namespace std;
vector <int> E[300005],e[300005];
int vis[300005],fa[300005],dep[300005],cnt[300005],qwq[300005],ans;
vector <int> v[300005];
inline int lca(int x,int y)//lca 
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y]) x=fa[x];
	while(x!=y) x=fa[x],y=fa[y];
	return x;
}
inline void dfsdfs(int u)// 
{
	for(auto v:e[u])
		dfsdfs(v),qwq[u]^=qwq[v];
	if(cnt[u]^qwq[u])
	{
		++ans,qwq[u]^=1;
	}
}
inline void add(int x,int y,int i)// 
{
	cnt[x]^=1,cnt[y]^=1;
	int L=lca(x,y);
	while(x!=L)
	{
		v[i].push_back(x);
		x=fa[x];
	}
	vector <int> V;
	while(y!=L)
	{
		V.push_back(y);
		y=fa[y];
	}
	V.push_back(L);
	reverse(V.begin(),V.end());
	for(auto t:V) v[i].push_back(t);
}
inline void DFS(int u)// 
{
	for(auto v:e[u])
		DFS(v),cnt[u]^=cnt[v];
}
inline void dfs(int u)// 
{
	vis[u]=1;
	for(auto v:E[u])
		if(!vis[v]) fa[v]=u,dep[v]=dep[u]+1,e[u].push_back(v),dfs(v);
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y,i);
	}
	DFS(1);
	int flag=1;
	for(int i=1;i<=n;i++)
		flag&=!cnt[i];
	if(flag)
	{
		cout << "YES\n";
		for(int i=1;i<=q;i++)
		{
			cout << v[i].size() << "\n";
			for(auto t:v[i])
				cout << t << " ";
			cout << "\n";
		}
		return 0;
	}
	cout << "NO\n";
	dfsdfs(1);
	cout << ans/2;
	return 0;
}