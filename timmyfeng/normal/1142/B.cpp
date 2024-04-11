#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	int log_n = 32 - __builtin_clz(n);

	vector<int> inv(n);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		inv[p - 1] = i;
	}

	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
		i = inv[i - 1];
	}

	vector<int> pos(n, -1);
	vector<pair<int, int>> cand;
	vector<vector<int>> pre(log_n, vector<int>(m, -1));

	for (int i = 0; i < m; ++i) {
		pre[0][i] = a[i] ? pos[a[i] - 1] : -1;
		for (int j = 1; j < log_n && pre[j - 1][i] != -1; ++j) {
			pre[j][i] = pre[j - 1][pre[j - 1][i]];
		}

		int cur = i;
		for (int j = log_n - 1; j >= 0; --j) {
			if (pre[j][cur] != -1) {
				cur = pre[j][cur];
			}
		}

		if (!a[cur]) {
			cand.emplace_back(cur, i);
		}

		pos[a[i]] = i;
	}

	int ndx = 0;
	int last = -1;
	vector<int> res(m, -1);
	sort(cand.begin(), cand.end());

	for (int i = 0; i < m; ++i) {
		if (a[i] == n - 1) {
			last = i;
		}

		while (ndx < int(cand.size()) && cand[ndx].first == i) {
			auto [l, r] = cand[ndx];
			++ndx;

			if (a[r] == n - 1) {
				res[r] = l;
			} else if (last != -1) {
				int cur = last;
				for (int j = log_n - 1; j >= 0; --j) {
					if (pre[j][cur] != -1 && a[pre[j][cur]] > a[r]) {
						cur = pre[j][cur];
					}
				}

				if (a[cur] == a[r] + 1) {
					res[r] = cur;
				}
			}
		}

		if (i) {
			res[i] = max(res[i], res[i - 1]);
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (res[r - 1] >= l - 1);
	}
	cout << "\n";
}