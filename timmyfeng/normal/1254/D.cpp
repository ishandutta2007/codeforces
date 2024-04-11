#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 150000 + 1;
const int MAG = 400;
const int LOG_N = 19;

int fen_tree[MX], n;
int time_in[MX], time_out[MX], t;
int sz[MX], par[LOG_N][MX], log_n;
vector<int> adj[MX];
map<int, int> heavy;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return add(1LL * a * b % M, M);
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

void upd(int a, int val) {
	for ( ; a <= n; a += a & -a) {
		fen_tree[a] = add(fen_tree[a], val);
	}
}

int qry(int a) {
	int res = 0;
	for ( ; a; a -= a & -a) {
		res = add(res, fen_tree[a]);
	}
	return res;
}

void dfs(int u) {
	if (int(adj[u].size()) > MAG) {
		heavy[u] = 0;
	}

	sz[u] = 1;
	time_in[u] = ++t;
	for (auto c : adj[u]) {
		if (c != par[0][u]) {
			par[0][c] = u;
			dfs(c);
			sz[u] += sz[c];
		}
	}
	time_out[u] = t;
}

bool is_anc(int u, int v) {
	return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

int suc(int u, int v) {
	for (int i = log_n - 1; i >= 0; --i) {
		if (!is_anc(par[i][v], u)) {
			v = par[i][v];
		}
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	time_out[0] = t;

	for (log_n = 1; (1 << log_n) < 2 * n; ++log_n) {
		for (int j = 1; j <= n; ++j) {
			par[log_n][j] = par[log_n - 1][par[log_n - 1][j]];
		}
	}

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int v, d;
			cin >> v >> d;

			int base = mul(d, mod_pow(n, M - 2));
			upd(1, mul(sz[v], base));
			upd(time_in[v], mul(n - sz[v], base));
			upd(time_out[v] + 1, mul(sz[v] - n, base));

			if (heavy.count(v)) {
				heavy[v] = add(heavy[v], base);
			} else {
				for (auto c : adj[v]) {
					if (c != par[0][v]) {
						upd(time_in[c], mul(-sz[c], base));
						upd(time_out[c] + 1, mul(sz[c], base));
					}
				}
			}
		} else {
			int v;
			cin >> v;

			int ans = qry(time_in[v]);
			for (auto [u, val] : heavy) {
				if (u != v && is_anc(u, v)) {
					ans = add(ans, mul(val, -sz[suc(u, v)]));
				}
			}
			cout << ans << "\n";
		}
	}
}