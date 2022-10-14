#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		set<char> x;
		for (int i = 0; i < n; i++) {
			x.insert(s[i]);
		}
		if (x.size() != n) {
			cout << "NO" << '\n';
			continue;
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int pos = -1;
			for (int j = 0; j < n; j++) {
				if (s[j] == (char) (i + 'a')) {
					pos = j;
				}
			}
			if (pos == -1) {
				ok = false;
				break;
			}
			if (i == n - 1 || i == 0) {
				continue;
			}
			if ((pos == 0 || s[pos - 1] > s[pos]) && (pos == n - 1 || s[pos + 1] > s[pos])) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}