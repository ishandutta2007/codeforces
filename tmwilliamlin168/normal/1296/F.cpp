#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e3;
int n, m, eu[mxN], ev[mxN], ew[mxN], a[mxN], b[mxN], g[mxN];
vector<int> adj[mxN];

bool dfs1(int u, int t, int w, int p=-1) {
	if(u==t)
		return 1;
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(v==p)
			continue;
		if(dfs1(v, t, w, u)) {
			ew[e]=max(ew[e], w);
			return 1;
		}
	}
	return 0;
}

int dfs2(int u, int t, int p=-1) {
	if(u==t)
		return 1e9;
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(v==p)
			continue;
		int a=dfs2(v, t, u);
		if(~a)
			return min(a, ew[e]);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<n; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	fill(ew+1, ew+n, 1);
	cin >> m;
	for(int i=0; i<m; ++i) {
		cin >> a[i] >> b[i] >> g[i], --a[i], --b[i];
		dfs1(a[i], b[i], g[i]);
	}
	for(int i=0; i<m; ++i)
		if(dfs2(a[i], b[i])^g[i]) {
			cout << "-1";
			exit(0);
		}
	for(int i=1; i<n; ++i)
		cout << ew[i] << "\n";
}