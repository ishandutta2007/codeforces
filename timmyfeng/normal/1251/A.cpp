#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<int> ok(26);
		for (int i = 0; i < (int)s.size(); ++i) {
			if (i + 1 < (int)s.size() && s[i] == s[i + 1]) {
				if (ok[s[i] - 'a'] == 0) {
					ok[s[i] - 'a'] = 1;
				}
				++i;
			} else {
				ok[s[i] - 'a'] = -1;
			}
		}
		for (int i = 0; i < 26; ++i) {
			if (ok[i] == -1) {
				cout << (char)('a' + i);
			}
		}
		cout << '\n';
	}
}