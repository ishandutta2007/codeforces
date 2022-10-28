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

		string t = s;
		string ans(n, '2');
		sort(t.begin(), t.end());

		int j = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[j]) {
				ans[i] = '1';
				++j;
			}
		}

		string chk;
		for (int i = 0; i < n; ++i) {
			if (ans[i] == '1') {
				chk += s[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (ans[i] == '2') {
				chk += s[i];
			}
		}

		if (chk == t) {
			cout << ans << "\n";
		} else {
			cout << "-\n";
		}
	}
}