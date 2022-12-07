#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> cnt; int big = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			big = max(big, ++cnt[x]);
		}
		int ans = max(0, 2 * big - n);
		if (n & 1) ans = max(ans, 1);
		cout << ans << "\n";
	}
	return 0;					
}