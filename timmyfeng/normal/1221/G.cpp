#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 40;

vector<int> adj[MX + 1];
bool vstd[MX + 1];
int col[MX + 1];
ll ans[1 << 3], adjma[MX + 1], dp[1 << (MX / 2)];

void dfs(int u) {
	vstd[u] = true;
	for (auto c : adj[u]) {
		if (!vstd[c]) {
			dfs(c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans[7] = 1LL << n;
	ans[0] = m ? 0 : ans[7];

	int ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].empty()) {
			++ct;
		}
	}
	ans[4] = ans[1] = 1LL << ct;

	ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			dfs(i);
			++ct;
		}
	}
	ans[5] = 1LL << ct;

	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		if (col[i]) continue;
		queue<int> q;
		col[i] = 1;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto c : adj[u]) {
				if (!col[c]) {
					col[c] = 3 - col[u];
					q.push(c);
				} else {
					if (col[c] != 3 - col[u]) {
						ok = false;
					}
				}
			}
		}
	}
	if (ok) {
		ans[2] = ans[5];
	}

	int n1 = n / 2;
	int n2 = (n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		adjma[i] |= 1LL << (i - 1);
		for (auto c : adj[i]) {
			adjma[i] |= 1LL << (c - 1);
		}
	}
	for (int ma = 0; ma < (1 << n1); ++ma) {
		ok = true;
		ll cur = 0;
		for (int i = 0; i < n1; ++i) {
			if (ma & (1 << i)) {
				if (cur & (1 << i)) {
					ok = false;
				}
				cur |= adjma[i + 1];
			}
		}
		if (ok) {
			++dp[cur >> n1];
		}
	}
	for (int i = 0; i < n2; ++i) {
		for (int ma = 0; ma < (1 << n2); ++ma) {
			if (ma & (1 << i)) {
				dp[ma] += dp[ma ^ (1 << i)];
			}
		}
	}
	for (int ma = 0; ma < (1 << n2); ++ma) {
		ok = true;
		ll cur = 0;
		for (int i = 0; i < n2; ++i) {
			if (ma & (1 << i)) {
				if (cur & (1LL << (i + n1))) {
					ok = false;
				}
				cur |= adjma[i + n1 + 1];
			}
		}
		if (ok) {
			ans[3] += dp[ma ^ ((1 << n2) - 1)];
		}
	}
	ans[6] = ans[3];

	ll sum = 0;
	for (int i = 0; i < (1 << 3); ++i) {
		if (__builtin_popcount(i) % 2) {
			sum += ans[i];
		} else {
			sum -= ans[i];
		}
	}
	cout << sum << '\n';
}