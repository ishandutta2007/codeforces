#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int ,int>> pt(n);
	for (auto& i : pt) {
		cin >> i.first >> i.second;
	}
	sort(pt.begin(), pt.end());

	int x = 0, y = 0;
	string ans = "";
	for (auto [px, py] : pt) {
		while (x < px) {
			ans += 'R';
			++x;
		}
		while (y < py) {
			ans += 'U';
			++y;
		}
		if (x != px || y != py) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
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