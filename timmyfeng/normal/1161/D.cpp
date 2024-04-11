#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

vector<vector<pair<int, int>>> adj;
vector<int> col;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

void add_edge(int u, int v, int w) {
	adj[u].emplace_back(v, w);
	adj[v].emplace_back(u, w);
}

bool dfs(int u) {
	bool res = true;
	for (auto [v, w] : adj[u]) {
		if (col[v] != -1) {
			res &= (col[v] ^ w) == col[u];
		} else {
			col[v] = col[u] ^ w;
			res &= dfs(v);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int m = s.size();
	reverse(s.begin(), s.end());

	adj.resize(2 * m);
	col.resize(2 * m);

	int ans = 0;
	for (int k = 1; k < m; ++k) {
		fill(adj.begin(), adj.end(), vector<pair<int, int>>());
		fill(col.begin(), col.end(), -1);

		add_edge(m + k, m - 1, 1);
		add_edge(m + k, m + k - 1, 1);

		for (int i = 0; i < m / 2; ++i) {
			add_edge(i, m - 1 - i, 0);
		}

		for (int i = 0; i < k / 2; ++i) {
			add_edge(m + i, m + k - 1 - i, 0);
		}

		for (int i = 0; i < m; ++i) {
			if (s[i] != '?') {
				add_edge(i, m + min(i, k), s[i] - '0');
			}
		}

		int cnt = 0;
		bool ok = true;
		for (int i = 0; i <= m + k; ++i) {
			if (col[i] == -1) {
				++cnt;
				col[i] = 0;
				ok &= dfs(i);
			}
		}

		if (ok) {
			ans = add(ans, mod_pow(2, cnt - 1));
		}
	}
	cout << ans << "\n";
}