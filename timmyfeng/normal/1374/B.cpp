#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		while (n % 6 == 0) {
			n /= 6;
			++ans;
		}

		while (n % 3 == 0) {
			n /= 3;
			ans += 2;
		}

		if (n != 1) {
			cout << -1 << "\n";
		} else {
			cout << ans << "\n";
		}
	}
}