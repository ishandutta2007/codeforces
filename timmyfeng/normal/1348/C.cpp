#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		sort(s.begin(), s.end());
		if (s[k - 1] != s[0]) {
			cout << s[k - 1] << '\n';
		} else {
			if (k < n && s.back() == s[k]) {
				cout << s[k - 1] << string((n - 1) / k, s.back()) << '\n';
			} else {
				cout << s.substr(k - 1) << '\n';
			}
		}
	}
}