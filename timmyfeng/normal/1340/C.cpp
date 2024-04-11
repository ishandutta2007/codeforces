#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e4;
const int MXT = 1e3;

int d[MX], dist[MX][MXT];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}
	sort(d, d + m);
	int g, r;
	cin >> g >> r;

	memset(dist, -1, sizeof dist);
	deque<pair<int, int>> dq;
	dq.emplace_back(0, 0);
	dist[0][0] = 0;

	auto upd = [&](int a, int t, int val) {
		if (t > g) return;
		if (t == g) {
			++val;
			t = 0;
		}
		if (dist[a][t] == -1) {
			dist[a][t] = val;
			if (t) {
				dq.emplace_front(a, t);
			} else {
				dq.emplace_back(a, t);
			}
		}
	};

	while (!dq.empty()) {
		auto [a, t] = dq.front();
		dq.pop_front();
		if (a) {
			upd(a - 1, t + d[a] - d[a - 1], dist[a][t]);
		}
		if (a + 1 < m) {
			upd(a + 1, t + d[a + 1] - d[a], dist[a][t]);
		}
	}

	ll ans = 1e18;
	for (int i = 0; i < g; ++i) {
		if (dist[m - 1][i] == -1) continue;
		ans = min(ans, (ll)dist[m - 1][i] * (g + r) + i - (i ? 0 : r));
	}
	cout << (ans == 1e18 ? -1 : ans) << '\n';
}