#include <bits/stdc++.h>
using namespace std;

pair<int, int> ans[100];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s, t;
		cin >> n >> s >> t;

		int m = 0;
		for (int i = 0; i < n; ++i) {
			bool ok = (s[i] == t[i]);
			for (int j = i + 1; j < n && !ok; ++j) {
				if (s[j] == s[i]) {
					ans[m++] = {j, i};
					swap(s[j], t[i]);
					ok = true;
				} else if (t[j] == s[i]) {
					ans[m++] = {i + 1, j};
					ans[m++] = {i + 1, i};
					swap(s[i + 1], t[j]);
					swap(s[i + 1], t[i]);
					ok = true;
				}
			}
			if (!ok) {
				m = -1;
				break;
			}
		}
		if (m == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << m << '\n';
			for (int i = 0; i < m; ++i) {
				cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
			}
		}
	}
}