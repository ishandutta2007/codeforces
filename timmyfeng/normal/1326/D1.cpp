#include <bits/stdc++.h>
using namespace std;

bool isPalin(string s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int j = n - 1, i = 0;
		while (i < j && s[i] == s[j]) {
			++i;
			--j;
		}
		string ans = "";
		for (int k = 1; k <= j - i + 1; ++k) {
			if (isPalin(s.substr(i, k))) {
				ans = s.substr(i, k);
			} else if (isPalin(s.substr(j - k + 1, k))) {
				ans = s.substr(j - k + 1, k);
			}
		}
		cout << s.substr(0, i) << ans << s.substr(j + 1) << '\n';
	}
}