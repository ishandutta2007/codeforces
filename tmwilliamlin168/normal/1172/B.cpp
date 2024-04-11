#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n;
vector<int> adj[mxN];

ll dfs(int u, int p=-1) {
	ll r=1;
	for(int i=1; i<=adj[u].size()-(p!=-1); ++i)
		r=r*(i+(u>0))%M;
	for(int v : adj[u])
		if(v^p)
			r=r*dfs(v, u)%M;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << dfs(0)*n%M;
}