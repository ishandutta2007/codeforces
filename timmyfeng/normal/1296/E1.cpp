#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	string ans(n, '0');
	for (int i = 1; i < n; ++i) {
		bool zero = false;
		for (int j = 0; j < i; ++j) {
			if (s[j] > s[i]) {
				if (ans[j] == '0') {
					zero = true;
				} else {
					cout << "NO\n";
					return 0;
				}
			}
		}
		if (zero) {
			ans[i] = '1';
		} else {
			ans[i] = '0';
		}
	}
	cout << "YES\n";
	cout << ans << '\n';
}