#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, c[mxN];
vector<int> adj[mxN];

void dfs(int u) {
	c[u]=0;
	for(int v : adj[u]) {
		if(~c[v])
			continue;
		dfs(v);
		if(!c[v])
			c[u]=1;
	}
}

void solve() {
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(c, -1, 4*n);
	dfs(0);
	int k=0;
	for(int i=0; i<n; ++i)
		k+=c[i];
	cout << k << "\n";
	for(int i=0; i<n; ++i)
		if(c[i])
			cout << i+1 << " ";
	cout << "\n";
	for(int i=0; i<n; ++i)
		adj[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}