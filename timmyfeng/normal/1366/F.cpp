#include <bits/stdc++.h> 
using namespace std;

const int MX = 2000 + 1;
const int M = 1e9 + 7;

vector<pair<int, int>> adj[MX];
int dp[MX][MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int floor_div(int a, int b) {
	return a / b - ((a ^ b) < 0 && a % b);
}

int intersect(pair<int, int> p, pair<int, int> q) {
	return floor_div(p.second - q.second, q.first - p.first);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	memset(dp, -1, sizeof dp);
	dp[0][1] = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] != -1) {
				for (auto [v, w] : adj[j]) {
					dp[i + 1][v] = max(dp[i + 1][v], dp[i][j] + w);
				}
			}
		}
	}

	vector<pair<int, int>> lns;
	for (int i = 1; i <= n; ++i) {
		if (dp[m][i] == -1)
			continue;
		int mx = 0;
		for (auto [_, w] : adj[i]) {
			mx = max(mx, w);
		}
		lns.emplace_back(mx, dp[m][i]);
	}
	sort(lns.begin(), lns.end());

	vector<pair<int, int>> hull;
	for (auto i : lns) {
		if (!hull.empty() && hull.back().first == i.first) {
			hull.pop_back();
		}

		while (hull.size() >= 2u &&
				intersect(i, hull.back()) <= intersect(i, hull[hull.size() - 2u])) {
			hull.pop_back();
		}
		hull.push_back(i);
	}

	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans = add(ans, *max_element(dp[i], dp[i] + n + 1) % M);
	}

	int left = 1;
	for (int i = 0; i < int(hull.size()); ++i) {
		int right = q - m;
		if (i + 1 < int(hull.size())) {
			right = min(right, intersect(hull[i], hull[i + 1]));
		}
		if (right < left)
			continue;

		int len = right - left + 1;
		ans = add(ans, mul(hull[i].second % M, len));
		ans = add(ans, mul(hull[i].first % M, mul(mul(len, add(right, left)), (M + 1) / 2)));
		left = right + 1;
	}
	cout << ans << '\n';
}