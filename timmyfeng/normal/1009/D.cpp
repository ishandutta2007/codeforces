#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> ans;
	for (int i = 1; i < n; ++i) {
		ans.emplace_back(i, i + 1);
	}
	for (int i = 1; i <= n && (int)ans.size() < m; ++i) {
		for (int j = i + 2; j <= n && (int)ans.size() < m; ++j) {
			if (__gcd(i, j) == 1) {
				ans.emplace_back(i, j);
			}
		}
	}

	if ((int)ans.size() != m) {
		cout << "Impossible" << '\n';
	} else {
		cout << "Possible" << '\n';
		for (auto [a, b] : ans) {
			cout << a << ' ' << b << '\n';
		}
	}
}