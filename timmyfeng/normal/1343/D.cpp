#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> cost(2 * k + 2);
	auto upd = [&](int a, int b, int val) {
		cost[a] += val;
		cost[b + 1] -= val;
	};
	for (int i = 0; i < n / 2; ++i) {
		int x = a[i];
		int y = a[n - 1 - i];
		if (x > y) {
			swap(x, y);
		}
		upd(2, x, 2);
		upd(x + 1, x + y - 1, 1);
		upd(x + y + 1, k + y, 1);
		upd(k + y + 1, 2 * k, 2);
	}

	int ans = 1e9;
	for (int i = 2; i <= 2 * k; ++i) {
		cost[i] += cost[i - 1];
		ans = min(ans, cost[i]);
	}
	cout << ans << '\n';
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