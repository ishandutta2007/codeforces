#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a) {
	int n = a.size();
	vector<int> ans;
	auto operation = [&](int i) {
		ans.push_back(i);
		rotate(a.begin() + i, a.begin() + i + 2, a.begin() + i + 3);
	};

	for (int i = 0; i < n - 3; ++i) {
		int mn = min_element(a.begin() + i, a.end()) - a.begin();
		while (mn - 2 >= i) {
			mn -= 2;
			operation(mn);
		}
		if (mn > i) {
			operation(i);
			operation(i);
		}
	}

	auto back_good = [&]() {
		return a[n - 3] <= a[n - 2] && a[n - 2] <= a[n - 1];
	};

	for (int i = 0; i < 3; ++i) {
		if (back_good())
			break;
		operation(n - 3);
	}

	if (back_good()) {
		return ans;
	} else {
		return {-1};
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		vector<int> perm(n);
		iota(perm.begin(), perm.end(), 0);
		sort(perm.begin(), perm.end(), [&](int u, int v) {
			return a[u] < a[v];
		});

		vector<int> key(n);
		for (int i = 0; i < n; ++i) {
			key[perm[i]] = i;
		}

		vector<int> ans = solve(key);
		if (!ans.empty() && ans[0] == -1) {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (a[i] == a[j]) {
						swap(key[i], key[j]);
						goto ok;
					}
				}
			} ok:
			ans = solve(key);
		}

		if (!ans.empty() && ans[0] == -1) {
			cout << -1 << "\n";
		} else {
			cout << ans.size() << "\n";
			for (auto& i : ans) {
				cout << i + 1 << " ";
			}
			cout << "\n";
		}
	}
}