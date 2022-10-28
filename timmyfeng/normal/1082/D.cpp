#include <bits/stdc++.h> 
using namespace std;

int a[501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> leaf;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1) {
			leaf.push_back(i);
			--a[i];
		}
	}

	if (leaf.empty()) {
		cout << "YES" << ' ' << n - 1 << '\n';
		cout << n - 1 << '\n';
		for (int i = 1; i < n; ++i) {
			cout << i << ' ' << i + 1 << '\n';
		}
		return 0;
	}

	if (leaf.size() == 1u) {
		cout << "YES" << ' ' << n - 1 << '\n';
		cout << n - 1 << '\n';
		int prev = leaf[0];
		for (int i = 1; i <= n; ++i) {
			if (!a[i])
				continue;
			cout << prev << ' ' << i << '\n';
			prev = i;
		}
		return 0;
	}

	vector<pair<int, int>> ans;
	int dia = n - int(leaf.size()) + 1;
	int cnt = 0;
	int prev = leaf[cnt++];
	for (int i = 1; i <= n; ++i) {
		if (!a[i])
			continue;
		ans.emplace_back(prev, i);
		if (a[prev]) {
			--a[prev];
		}
		--a[i];
		prev = i;
	}
	ans.emplace_back(prev, leaf[cnt++]);
	if (a[prev]) {
		--a[prev];
	}
	for ( ; cnt < int(leaf.size()); ++cnt) {
		int i = 0;
		while (i <= n && !a[i]) {
			++i;
		}
		if (i > n) {
			cout << "NO" << '\n';
			return 0;
		}
		ans.emplace_back(leaf[cnt], i);
		--a[i];
	}
	cout << "YES" << ' ' << dia << '\n';
	cout << n - 1 << '\n';
	for (auto [u, b] : ans) {
		cout << u << ' ' << b << '\n';
	}
}