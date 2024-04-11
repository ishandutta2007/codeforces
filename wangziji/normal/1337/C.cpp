#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector <int> e[200005];
priority_queue <pair<int,int> > q;
int dep[200005],sz[200005],cnt[200005],fa[200005];
inline void dfs(int u,int f)
{
	sz[u]=1,fa[u]=f;
	for(auto v:e[u])
	{
		if(v==f) continue;
		++cnt[u],dep[v]=dep[u]+1,dfs(v,u),sz[u]+=sz[v];
	}
}
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(!cnt[i]) q.push({dep[i]-sz[i],i});
	long long ans=0;
	for(int i=1;i<=k;i++) 
	{
		int x=q.top().second;
		ans+=q.top().first+1;
		q.pop();
		if(!--cnt[fa[x]])
			q.push({dep[fa[x]]-sz[fa[x]],fa[x]});
	}
	cout << ans;
	return 0;
}