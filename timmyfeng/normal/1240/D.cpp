#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<pair<int, int>> stk;
	vector<map<int, int>> nxt_x(n + 1);
	vector<vector<int>> nxt(1, vector<int>(n + 1));

	for (int i = n - 1; i >= 0; --i) {
		if (nxt_x[i + 1].count(a[i])) {
			nxt[0][i] = nxt_x[i + 1][a[i]] + 1;
			swap(nxt_x[nxt[0][i]], nxt_x[i]);
		} else {
			nxt[0][i] = -1;
		}
		nxt_x[i][a[i]] = i;
	}
	nxt[0][n] = -1;

	int log_n = 1;
	for ( ; (1 << log_n) < 2 * n; ++log_n) {
		nxt.emplace_back(n + 1);
		for (int i = 0; i <= n; ++i) {
			if (nxt[log_n - 1][i] == -1) {
				nxt[log_n][i] = -1;
			} else {
				nxt[log_n][i] = nxt[log_n - 1][nxt[log_n - 1][i]];
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = i;
		for (int j = log_n - 1; j >= 0; --j) {
			if (nxt[j][cur] != -1) {
				cur = nxt[j][cur];
				ans += 1 << j;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}