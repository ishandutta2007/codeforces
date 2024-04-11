#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 5e3;

int ft[MX * 2 + 1];

void upd(int a, int val) {
	for (a += MX; a < MX * 2 + 1; a |= a + 1) {
		ft[a] += val;
	}
}

int query(int a) {
	int res = 0;
	for (a += MX; a >= 0; a &= a + 1, --a) {
		res += ft[a];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> ver, hor;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			ver.emplace_back(x1, min(y1, y2), max(y1, y2));
		} else {
			hor.emplace_back(max(x1, x2), min(x1, x2), y1);
		}
	}
	sort(ver.begin(), ver.end());
	sort(hor.begin(), hor.end());

	ll ans = 0;
	int v = ver.size();
	for (int i = 0; i < v; ++i) {
		auto [l, lb, ub] = ver[i];
		memset(ft, 0, sizeof ft);
		vector<pair<int, int>> pos;
		for (auto [x2, x1, y] : hor) {
			if (x1 <= l && x2 >= l && y >= lb && y <= ub) {
				upd(y, 1);
				pos.emplace_back(x2, y);
			}	
		}
		reverse(pos.begin(), pos.end());
		for (int k = i + 1; k < v; ++k) {
			auto [r, y1, y2] = ver[k];
			while (!pos.empty() && pos.back().first < r) {
				upd(pos.back().second, -1);
				pos.pop_back();
			}
			ll cnt = query(y2) - query(y1 - 1);
			ans += cnt * (cnt - 1) / 2;
		}
	}
	cout << ans << '\n';
}