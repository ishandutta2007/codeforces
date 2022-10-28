#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 1;

struct linear_hull {

	struct line {
		long long m, b;
		int floor_div(long long a, long long b) {
			return a / b - ((a ^ b) < 0 && a % b);
		}
		long long intersect(line oth) {
			return floor_div(b - oth.b, oth.m - m);
		}
		long long evaluate(long long x) {
			return m * x + b;
		}
	};

	vector<line> hull;

	void upd_back(long long m, long long b) {
		line ln = {m, b};

		if (!hull.empty() && ln.m == hull.back().m) {
			if (ln.b <= hull.back().b)
				return;
			hull.pop_back();
		}

		while (hull.size() >= 2u) {
			long long x1 = ln.intersect(hull[hull.size() - 1u]);
			long long x2 = ln.intersect(hull[hull.size() - 2u]);
			if (x1 > x2)
				break;
			hull.pop_back();
		}
		hull.push_back(ln);
	}

	long long qry_back(long long x) {
		if (hull.empty())
			return 0;

		while (hull.size() >= 2u) {
			long long y1 = hull[hull.size() - 1u].evaluate(x);
			long long y2 = hull[hull.size() - 2u].evaluate(x);
			if (y1 > y2)
				break;
			hull.pop_back();
		}
		return hull.back().evaluate(x);
	}

} cht;

vector<int> adj[MX];
long long res[MX];
long long dp[MX];
long long ans;
int sz[MX];

void dfs(int u, int p) {
	sz[u] = 1;
	for (auto c : adj[u]) {
		if (c != p) {
			dfs(c, u);
			sz[u] += sz[c];
		}
	}

	dp[u] = 1LL * sz[u] * (sz[u] - 1) / 2;
	for (auto c : adj[u]) {
		if (c != p) {
			int cnt = sz[u] - sz[c];
			dp[u] = min(dp[u], dp[c] + 1LL * cnt * (cnt - 1) / 2);
		}
	}
}

void dfs_reroot(int u, int p) {
	sz[u] += sz[p];
	long long pre = dp[u];

	sort(adj[u].begin(), adj[u].end(), [&](int a, int b) {
		return sz[a] < sz[b];
	});

	cht.hull.clear();
	for (auto c : adj[u]) {
		int cnt = sz[u] - sz[c];
		res[c] = 1LL * cnt * (cnt - 1) / 2 - cht.qry_back(cnt);
		cht.upd_back(sz[c], -1LL * sz[c] * (sz[c] + 1) / 2 - dp[c]);
	}

	cht.hull.clear();
	reverse(adj[u].begin(), adj[u].end());
	for (auto c : adj[u]) {
		int cnt = sz[u] - sz[c];
		res[c] = min(res[c], 1LL * cnt * (cnt - 1) / 2 - cht.qry_back(-cnt));
		cht.upd_back(-sz[c], -1LL * sz[c] * (sz[c] + 1) / 2 - dp[c]);
	}

	ans = min(ans, 1LL * sz[u] * (sz[u] - 1) / 2 - cht.qry_back(-sz[u]));

	for (auto c : adj[u]) {
		if (c != p) {
			dp[u] = res[c];
			sz[u] -= sz[c];
			dfs_reroot(c, u);
			sz[u] += sz[c];
		}
	}

	dp[u] = pre;
	sz[u] -= sz[p];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	ans = 1LL * n * (n - 1) / 2;
	dfs_reroot(1, 0);

	cout << 1LL * n * (n - 1) - ans << "\n";
}