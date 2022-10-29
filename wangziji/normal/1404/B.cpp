#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> e[200005];
int dis[200005],vis[200005];
inline void dfs(int u)
{
	vis[u]=1;
	for(auto v:e[u])
	{
		if(vis[v]) continue;
		dis[v]=dis[u]+1;
		dfs(v);
	}
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,a,b,da,db;
		cin >> n >> a >> b >> da >> db;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(db<=da*2)
		{
			puts("Alice");
			continue;
		}
		for(int i=1;i<=n;i++) dis[i]=vis[i]=0;
		dfs(a);
		if(dis[b]<=da)
		{
			puts("Alice");
			continue;
		}
		int mx=-1,p=0;
		for(int i=1;i<=n;i++)
			if(dis[i]>mx) mx=dis[i],p=i;
		for(int i=1;i<=n;i++) dis[i]=vis[i]=0;
		dfs(p);
		for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
	//	cout << mx << "\n";
		if(mx<=da*2) puts("Alice");
		else puts("Bob");
	}
	return 0;
}