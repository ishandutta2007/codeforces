#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, int>> pts;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		pts.emplace_back(l, 0);
		pts.emplace_back(r + 1, 1);
	}
	sort(pts.begin(), pts.end());

	int cnt = 0;
	ll pre_x = 0;
	vector<ll> ans(n + 1);
	for (auto [x, type] : pts) {
		if (type) {
			ans[cnt] += x - pre_x;
			--cnt;
		} else {
			ans[cnt] += x - pre_x;
			++cnt;
		}
		pre_x = x;
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}