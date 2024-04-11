#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	int mn = 0;
	for (int i = 0; i < n; ++i) {
		mn = max(mn, a[i] - i);
	}

	vector<pair<int, int>> pts;
	for (int i = p; i <= n; ++i) {
		if (i == n || a[i - 1] != a[i]) {
			pts.emplace_back(a[i - 1] - i + p, -1);
			if (i < n) {
				pts.emplace_back(a[i] - i + p, 1);
			}
		}
	}
	sort(pts.begin(), pts.end());

	int bal = 0;
	int pre = mn;
	vector<int> ans;
	for (auto [x, type] : pts) {
		if (!bal) {
			for (int i = pre; i < x; ++i) {
				ans.push_back(i);
			}
		}
		bal += type;
		pre = max(pre, x);
	}

	cout << ans.size() << "\n";
	for (auto& i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}