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
		int n = s.size();
		if ((s[n - 1] - '0') % 2 == 0) {
			cout << "0\n";
		} else {
			if ((s[0] - '0') % 2 == 0) {
				cout << "1\n";
			} else {
				bool ima = false;
				for (int i = 0; i < n; i++) {
					if ((s[i] - '0') % 2 == 0) {
						ima = true;
					}
				}
				cout << (ima ? 2 : -1) << '\n';
			}
		}
	}
	return 0;
}