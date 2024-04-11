#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		if ((int)s.length() == 2) {
			cout << s << endl;
			continue;
		}
		for (int i = 0; i < (int)s.length(); i += 2) {
			if (i == 0) {
				cout << s[i] << s[i + 1];
				continue;
			}
			if (s[i] != s[i - 1]) cout << s[i];
			cout << s[i + 1];
		}
		cout << endl;
	}
	return 0;
}