#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> d(n);
	for (auto& i : d) {
		cin >> i;
	}

	int i = 0, l = 0, r = n - 1;
	vector<pair<int, int>> ans;
	while (l <= r) {
		for (int j = i + 1; j <= i + d[r]; ++j) {
			ans.emplace_back(i, j);
		}
		bool ok = true;
		for (int j = l; j <= r; ++j) {
			--d[j];
			ok &= !!d[j];
		}
		if (!ok) {
			++l;
			--r;
		}
		++i;
	}

	cout << ans.size() << '\n';
	for (auto [a, b] : ans) {
		cout << a + 1 << ' ' << b + 1 << '\n';
	}
}