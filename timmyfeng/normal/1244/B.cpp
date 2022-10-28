#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = n;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				ans = max(ans, 2 * max(n - i, i + 1));
			}
		}
		cout << ans << '\n';
	}
}