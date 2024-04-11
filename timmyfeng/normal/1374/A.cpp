#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y, n;
		cin >> x >> y >> n;
		int ans = (n - n % x) + y;
		while (ans > n) {
			ans -= x;
		}
		cout << ans << "\n";
	}
}