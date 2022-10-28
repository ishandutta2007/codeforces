#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, k, x, y, ans;
vector<int> adj[mxN], path;
bool need[mxN];

bool dfs1(int u=x, int p=-1) {
	path.push_back(u);
	if (u==y)
		return 1;
	for (int v : adj[u])
		if (v!=p)
			if (dfs1(v, u))
				return 1;
	path.pop_back();
	return 0;
}

void dfs2(int u, int p) {
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs2(v, u);
		need[u]|=need[v];
		ans+=2*need[v];
	}
}

void dfs3(int u, int p1, int p2) {
	for (int v : adj[u]) {
		if (v==p1||v==p2)
			continue;
		dfs3(v, u, u);
		need[u]|=need[v];
		ans+=2*need[v];
	}
}

void solve() {
	cin >> n >> k >> x >> y, --x, --y;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		need[i]=0;
	}
	for (int i=0; i<k; ++i) {
		int bad;
		cin >> bad, --bad;
		need[bad]=1;
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	path.clear();
	dfs1();
	ans=path.size()-1;
	if (x==y)
		dfs2(x, -1);
	else {
		dfs2(x, path[1]);
		dfs2(path.back(), path.end()[-2]);
		for (int i=1; i+1<path.size(); ++i)
			dfs3(path[i], path[i-1], path[i+1]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}