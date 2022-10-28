#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ans = 1e9;
		for (int i = 1; i * i <= n; ++i) {
			if (n % i)
				continue;
			if (i <= k) {
				ans = min(ans, n / i);
			}
			if (n / i <= k) {
				ans = min(ans, i);
			}
		}
		cout << ans << '\n';
	}
}