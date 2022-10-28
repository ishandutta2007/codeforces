#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int M = (119 << 23) + 1;

vector<pair<int, int>> adj[MX];
int dp[MX][3];

int add(int a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

void dfs(int u, int t) {
	if (adj[u].empty()) {
		dp[u][0] = 0;
		dp[u][1] = 1;
		dp[u][2] = 1;
		return;
	}

	vector<int> suf_prod;
	vector<int> pre_prod = {1};
	for (auto [c, i] : adj[u]) {
		adj[c].erase(find(adj[c].begin(), adj[c].end(), make_pair(u, i)));

		dfs(c, i);
		pre_prod.push_back(add(dp[c][0], dp[c][1]));
		suf_prod.push_back(add(dp[c][0], dp[c][2]));
	}
	suf_prod.push_back(1);

	int k = adj[u].size();
	for (int i = 1; i <= k; ++i) {
		pre_prod[i] = mul(pre_prod[i], pre_prod[i - 1]);
		suf_prod[k - i] = mul(suf_prod[k - i], suf_prod[k - i + 1]);
	}

	dp[u][2] = pre_prod[k];
	for (int i = 0; i < k; ++i) {
		auto [c, tt] = adj[u][i];
		int res = mul(pre_prod[i], mul(dp[c][2], suf_prod[i + 1]));
		if (tt < t) {
			dp[u][0] = add(dp[u][0], res);
		} else {
			dp[u][2] = add(dp[u][2], res);
		}
	}

	int d = lower_bound(adj[u].begin(), adj[u].end(), t, [&](pair<int, int> a, int b) {
		return a.second < b;
	}) - adj[u].begin();

	dp[u][1] = mul(pre_prod[d], suf_prod[d]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	dfs(1, n);

	cout << add(dp[1][0], dp[1][1]) << "\n";
}