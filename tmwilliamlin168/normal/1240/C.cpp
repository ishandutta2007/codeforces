#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, k;
vector<ar<int, 2>> adj[mxN];
ll dp[mxN][2];

void dfs(int u=0, int p=-1) {
	//cout << u << " " << p << endl;
	ll base=0;
	vector<ll> a;
	for(ar<int, 2> v : adj[u]) {
		if(v[0]^p) {
			dfs(v[0], u);
			dp[v[0]][1]+=v[1];
			base+=dp[v[0]][0];
			a.push_back(dp[v[0]][1]-dp[v[0]][0]);
		}
	}
	sort(a.begin(), a.end(), greater<ll>());
	//for 0, we take k children atmost
	//for 1, we take k-1 children at most
	for(int i : {0, 1}) {
		dp[u][i]=base;
		for(int j=0; j<min(k-i, (int)a.size()); ++j)
			dp[u][i]+=max(a[j], 0ll);
	}
}

void solve() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		adj[i].clear();
	for(int i=1; i<n; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(dp, 0, n*sizeof(dp[0]));
	dfs();
	cout << dp[0][0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--)
		solve();
}