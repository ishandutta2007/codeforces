#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue <int> q;
vector <int> e[200005];
int deg[200005],sz[200005],vis[200005];
inline void dfs(int u,int f)
{
	vis[u]=sz[u]=1;
	for(auto v:e[u])
		if(!vis[v]&&v!=f) dfs(v,u),sz[u]+=sz[v];
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) e[i].clear(),vis[i]=1,deg[i]=0;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			++deg[u],++deg[v];
		}
		for(int i=1;i<=n;i++)
		{
			if(deg[i]==1)
			{
				vis[i]=0;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(auto v:e[x])
				if(--deg[v]==1) q.push(v);
		}
		long long ans=(long long)n*(n-1);
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				dfs(i,0);
				ans-=(long long)sz[i]*(sz[i]-1)/2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}