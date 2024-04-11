#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a,b,c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i <= 50; ++i) {
			for (int j = 0; j <= 50; ++j) {
				if (i > a || 2 * i + j > b || 2 * j > c) continue;
				ans = max(ans, i * 3 + j * 3);
			}
		}
		cout << ans << '\n';
	}
}