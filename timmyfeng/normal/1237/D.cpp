#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;
const int LOG_N = 19;

int sparse[LOG_N][MX], nxt[MX], ans[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> vals;
	for (int i = 0; i < n; ++i) {
		cin >> sparse[0][i];
		sparse[0][i + n] = sparse[0][i];
		vals.emplace_back(sparse[0][i], i);
	}
	sort(vals.rbegin(), vals.rend());

	if (vals[n - 1].first >= (vals[0].first + 1) / 2) {
		for (int i = 0; i < n; ++i) {
			cout << "-1 ";
		}
		cout << "\n";
		return 0;
	}

	vector<pair<int, int>> stk;
	for (int i = 2 * n - 1; i >= 0; --i) {
		while (!stk.empty() && stk.back().first <= sparse[0][i]) {
			stk.pop_back();
		}
		if (i < n) {
			nxt[i] = stk.empty() ? i + n : stk.back().second;
		}
		stk.emplace_back(sparse[0][i], i);
	}

	for (int i = 1; (1 << i) < 4 * n; ++i) {
		int len = (1 << (i - 1));
		for (int j = 0; j + len < 2 * n; ++j) {
			sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + len]);
		}
	}

	for (auto [a, i] : vals) {
		int lb = i + 1;
		int rb = nxt[i];
		while (lb < rb) {
			int mb = (lb + rb + 1) / 2;

			int log_n = 31 - __builtin_clz(mb - i);
			int mn = min(sparse[log_n][i], sparse[log_n][mb - (1 << log_n)]);
			if (mn >= (a + 1) / 2) {
				lb = mb;
			} else {
				rb = mb - 1;
			}
		}

		if (lb == nxt[i]) {
			ans[i] = ans[nxt[i] % n];
		}
		ans[i] += lb - i;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}