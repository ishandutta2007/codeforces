#include <bits/stdc++.h>

using namespace std;

int t, n;
pair<int, int> a[222000];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i].first;
		for (int i = 0; i < n; i++) cin >> a[i].second;
		sort(a, a + n);
		int ans = 0, r = 1, c = 1;
		for (int i = 0; i < n; i++) {
			int x = a[i].first - r;
			int y = a[i].second - c;
			if (x == y) 
				ans += (r + c) % 2 == 1 ? 0 : x;
			else 
				ans += (r + c) % 2 == 1 ? (x - y + 1) / 2 : (x - y) / 2;
			r = a[i].first;
			c = a[i].second;
		}
		cout << ans << "\n";
	}
	
	return 0;					
}