#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans = "";
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			continue;
		}
		if (s[i] != s[i + 1]) {
			ans += s[i];
			ans += s[i + 1];
			i++;
		} else {
			++cnt;
		}
	}
	cout << n - (int) ans.size() << '\n' << ans << '\n';
	return 0;
}