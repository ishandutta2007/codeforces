#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int AL = 14;
const int MX = 1000;

ll dp[1 << AL][MX + 1], val[AL + 1][MX + 1], cost[MX + 1];
int to[MX + 1][AL], dest[AL + 1][MX + 1], link[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, sz = 1;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		string t;
		int c;
		cin >> t >> c;
		int cur = 0;
		for (auto i : t) {
			if (!to[cur][i - 'a']) {
				to[cur][i - 'a'] = sz++;
			}
			cur = to[cur][i - 'a'];
		}
		cost[cur] += c;
	}
	string s;
	cin >> s;

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < AL; ++i) {
			if (to[u][i]) {
				link[to[u][i]] = u ? to[link[u]][i] : 0;
				cost[to[u][i]] += cost[link[to[u][i]]];
				q.push(to[u][i]);
			} else {
				to[u][i] = to[link[u]][i];
			}
		}
	}

	int cnt = -1;
	for (int i = 0; i < (1 << 14); ++i) {
		fill(dp[i], dp[i] + sz, -1e18);
	}
	for (int i = 0, j; i <= (int)s.size(); i = j + 1, ++cnt) {
		for (j = i; j < (int)s.size() && s[j] != '?'; ++j);
		for (int k = 0; k < sz; ++k) {
			ll sum = 0;
			int cur = k;
			for (int m = i; m < j; ++m) {
				cur = to[cur][s[m] - 'a'];
				sum += cost[cur];
			}
			if (cnt == -1) {
				dp[0][cur] = sum;
				break;
			}
			dest[cnt][k] = cur;
			val[cnt][k] = sum;
		}
	}

	ll ans = -1e18;
	for (int ma = 0; ma < (1 << AL); ++ma) {
		int v = __builtin_popcount(ma);
		if (v > cnt) continue;
		for (int i = 0; i < sz; ++i) {
			if (dp[ma][i] == -1e18) continue;
			if (v == cnt) {
				ans = max(ans, dp[ma][i]);
				continue;
			}
			for (int j = 0; j < AL; ++j) {
				if (ma & (1 << j)) continue;
				int nw = ma | (1 << j);
				int u = to[i][j];
				dp[nw][dest[v][u]] = max(dp[nw][dest[v][u]], dp[ma][i] + cost[u] + val[v][u]);
			}
		}
	}
	cout << ans << '\n';
}