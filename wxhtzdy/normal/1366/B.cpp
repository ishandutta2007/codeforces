#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;
		int left = x, right = x;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (a <= right && b >= left) {
				right = max(right, b);
				left = min(left, a);
			}
		}
		int ans = right - left + 1;
		cout << ans << endl;
	}
	return 0;
}