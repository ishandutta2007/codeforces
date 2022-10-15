#include <bits/stdc++.h>
using namespace std;
 
const int mxN=1e4;
int n, c[mxN], ans;
vector<int> adj[mxN];
 
void dfs(int u=0, int cp=0) {
	if(c[u]^cp)
		++ans;
	for(int v : adj[u])
		dfs(v, c[u]);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=1, p; i<n; ++i) {
		cin >> p, --p;
		adj[p].push_back(i);
	}
	for(int i=0; i<n; ++i)
		cin >> c[i];
	dfs();
	cout << ans;
}