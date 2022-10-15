#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, x[mxN];
vector<int> adj[mxN], ans;

void dfs(int u=0, int p=-1) {
	ans.push_back(u);
	for(int v : adj[u]) {
		if(v==p)
			continue;
		x[v]=-x[v];
		dfs(v, u);
		ans.push_back(u);
		x[u]=-x[u];
	}
	if(x[u]<0) {
		if(u) {
			ans.push_back(p);
			ans.push_back(u);
			x[p]=-x[p];
		} else {
			ans.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for(int a : ans)
		cout << a+1 << " ";
}