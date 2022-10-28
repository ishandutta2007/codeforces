#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	vector<pair<int, int>> ans;

	auto do_swap = [&](int u, int v) {
		if (u > v) {
			swap(u, v);
		}

		if (u == 1) {
			if (v <= n / 2) {
				ans.emplace_back(v, n);
				ans.emplace_back(1, n);
				ans.emplace_back(v, n);
			} else {
				ans.emplace_back(1, v);
			}
		} else if (v == n) {
			if (u > n / 2) {
				ans.emplace_back(1, u);
				ans.emplace_back(1, n);
				ans.emplace_back(1, u);
			} else {
				ans.emplace_back(u, n);
			}
		} else {
			if (u <= n / 2) {
				ans.emplace_back(u, n);
			} else {
				ans.emplace_back(1, u);
			}

			if ((u <= n / 2) ^ (v <= n / 2)) {
				ans.emplace_back(1, n);
			}

			if (v <= n / 2) {
				ans.emplace_back(v, n);
			} else {
				ans.emplace_back(1, v);
			}

			if ((u <= n / 2) ^ (v <= n / 2)) {
				ans.emplace_back(1, n);
			}

			if (u <= n / 2) {
				ans.emplace_back(u, n);
			} else {
				ans.emplace_back(1, u);
			}
		}
		pos[a[u]] = v;
		pos[a[v]] = u;
		swap(a[u], a[v]);
	};

	for (int i = 1; i <= n; ++i) {
		if (pos[i] != i) {
			do_swap(i, pos[i]);
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i.first << " " << i.second << "\n";
	}
}