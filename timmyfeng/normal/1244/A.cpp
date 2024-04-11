#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a - 1) / c + 1, y = (b - 1) / d + 1;
		if (x + y > k) {
			cout << -1 << '\n';
		} else {
			cout << x << ' ' << y << '\n';
		}
	}
}