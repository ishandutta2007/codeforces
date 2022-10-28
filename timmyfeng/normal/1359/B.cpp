#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		y = min(y, x * 2);

		int ans = 0;
		while (n--) {
			string s;
			cin >> s;
			for (int i = 0; i < m; ++i) {
				if (s[i] == '*')
					continue;
				if (i + 1 < m && s[i + 1] == '.') {
					ans += y;
					++i;
				} else {
					ans += x;
				}
			}
		}
		cout << ans << '\n';
	}
}