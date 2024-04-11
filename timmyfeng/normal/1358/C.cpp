#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll x_diff = x2 - x1;
		ll y_diff = y2 - y1;
		if (x_diff > y_diff) {
			swap(x_diff, y_diff);
		}

		ll start = x_diff * (x_diff + 1) / 2;
		ll mid = x_diff * (y_diff - x_diff);
		ll end = start - x_diff;
		cout << start + mid + end + 1 << '\n';
	}
}