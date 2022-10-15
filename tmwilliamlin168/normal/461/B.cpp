#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, x[mxN];
ll dp1[mxN], dp2[mxN];
vector<int> adj[mxN];

void dfs(int u=0) {
	dp1[u]=1;
	for(int v : adj[u]) {
		dfs(v);
		dp1[v]=(dp1[v]+dp2[v])%M;
		dp2[u]=(dp2[u]*dp1[v]+dp1[u]*dp2[v])%M;
		dp1[u]=dp1[u]*dp1[v]%M;
	}
	if(x[u]) {
		dp2[u]=dp1[u];
		dp1[u]=0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<n; ++i) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	for(int i=0; i<n; ++i)
		cin >> x[i];
	dfs();
	cout << dp2[0];
}