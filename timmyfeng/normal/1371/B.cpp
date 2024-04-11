#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;

		long long ans = 0;
		if (r >= n) {
			r = n - 1;
			++ans;
		}
		ans += 1LL * r * (r + 1) / 2;
		cout << ans << "\n";
	}
}