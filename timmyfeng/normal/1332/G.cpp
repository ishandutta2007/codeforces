#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;
const int LOGN = 19;

int ans3[MX][3], ans4[MX][4], a[MX], n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	vector<int> mx, mn;
	set<int> not_any, not_mx, not_mn;
	for (int i = n; i; --i) {
		if (i < n) {
			for (int j = 0; j < 4; ++j) {
				ans4[i][j] = ans4[i + 1][j];
			}
			for (int j = 0; j < 3; ++j) {
				ans3[i][j] = ans3[i + 1][j];
			}
		}

		while (!mx.empty() && a[mx.back()] < a[i]) {
			not_mx.insert(mx.back());
			if (not_mn.count(mx.back())) {
				not_any.insert(mx.back());
			}
			mx.pop_back();
		}
		mx.push_back(i);

		while (!mn.empty() && a[mn.back()] > a[i]) {
			not_mn.insert(mn.back());
			if (not_mx.count(mn.back())) {
				not_any.insert(mn.back());
			}
			mn.pop_back();
		}
		mn.push_back(i);

		auto it1 = lower_bound(mx.begin(), mx.end(), i, [&](int u, int v) {
			return a[u] > a[v];
		});
		auto it2 = lower_bound(mn.begin(), mn.end(), i, [&](int u, int v) {
			return a[u] < a[v];
		});
		int u = it1 == mx.begin() ? 0 : *(--it1);
		int v = it2 == mn.begin() ? 0 : *(--it2);

		if (u && v) {
			auto it = not_any.lower_bound(max(u, v));
			if (it != not_any.end() && (!ans4[i][3] || *it <= ans4[i][3])) {
				ans4[i][0] = i;
				ans4[i][1] = *lower_bound(mx.begin(), mx.end(), *it, greater<int>());
				ans4[i][2] = *lower_bound(mn.begin(), mn.end(), *it, greater<int>());
				ans4[i][3] = *it;
				if (ans4[i][1] > ans4[i][2]) {
					swap(ans4[i][1], ans4[i][2]);
				}
			}
		}

		if (u) {
			auto it = not_mx.lower_bound(u);
			if (it != not_mx.end() && (!ans3[i][2] || *it <= ans3[i][2])) {
				ans3[i][0] = i;
				ans3[i][1] = *lower_bound(mx.begin(), mx.end(), *it, greater<int>());
				ans3[i][2] = *it;
			}
		}

		if (v) {
			auto it = not_mn.lower_bound(v);
			if (it != not_mn.end() && (!ans3[i][2] || *it <= ans3[i][2])) {
				ans3[i][0] = i;
				ans3[i][1] = *lower_bound(mn.begin(), mn.end(), *it, greater<int>());
				ans3[i][2] = *it;
			}
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (ans4[l][3] && ans4[l][3] <= r) {
			cout << 4 << '\n';
			for (int i = 0; i < 4; ++i) {
				cout << ans4[l][i] << ' ';
			}
			cout << '\n';
		} else if (ans3[l][2] && ans3[l][2] <= r) {
			cout << 3 << '\n';
			for (int i = 0; i < 3; ++i) {
				cout << ans3[l][i] << ' ';
			}
			cout << '\n';
		} else {
			cout << 0 << '\n';
			cout << '\n';
		}
		if (clock() > 1900) {
			return q;
		}
	}
}