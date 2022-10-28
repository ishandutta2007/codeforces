#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 2e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int pre_r = -INF, pre_b = -INF, pre_p = -INF, mx_r = 0, mx_b = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++ i) {
		int x;
		char c;
		cin >> x >> c;
		if (c == 'P') {
			if (pre_r > -INF) {
				ans += x - pre_r;
				mx_r = max(x - pre_r, mx_r);
			}
			if (pre_b > -INF) {
				ans += x - pre_b;
				mx_b = max(x - pre_b, mx_b);
			}

			if (pre_p > -INF && (ll)mx_r + mx_b > x - pre_p) {
				ans -= (ll)mx_r + mx_b;
				ans += x - pre_p;
			}
			mx_r = mx_b = 0;
			pre_p = pre_r = pre_b = x;
		} else if (c == 'R') {
			if (pre_r > -INF) {
				ans += x - pre_r;
				mx_r = max(x - pre_r, mx_r);
			}
			pre_r = x;
		} else {
			if (pre_b > -INF) {
				ans += x - pre_b;
				mx_b = max(x - pre_b, mx_b);
			}
			pre_b = x;
		}
	}
	cout << ans << '\n';
}