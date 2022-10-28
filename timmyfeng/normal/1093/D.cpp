#include <bits/stdc++.h> 
using namespace std;

const int MX = 3e5 + 1;
const int M = (119 << 23) + 1;

int pow2[MX], ans, odd, even;
bitset<MX> vstd, col;
vector<int> adj[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long) a * b % M;
}

void init() {
	pow2[0] = 1;
	for (int i = 1; i < MX; ++i) {
		pow2[i] = add(pow2[i - 1], pow2[i - 1]);
	}
}

void dfs(int u) {
	vstd[u] = true;
	if (col[u]) {
		++odd;
	} else {
		++even;
	}
	for (auto c : adj[u]) {
		if (vstd[c]) {
			if (col[c] == col[u]) {
				ans = 0;
			}
		} else {
			col[c] = !col[u];
			dfs(c);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	fill_n(adj, n + 1, vector<int>());
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vstd.reset();
	col.reset();
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			odd = even = 0;
			dfs(i);
			int res = add(pow2[even], pow2[odd]);
			ans = mul(ans, res);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}