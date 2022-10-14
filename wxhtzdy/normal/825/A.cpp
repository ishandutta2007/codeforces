#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string  s;
	cin >> s;
	if (n == 1 && s == "0") {
		cout << 0;
		return 0;
	}
	int ans = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			tmp += 1;
		} else {
			if (tmp) {
				ans *= 10;
				ans += tmp;
				tmp = 0;
			}
			if (i == n - 1 || s[i + 1] == '0') {
				ans *= 10;
			}
		}
	}
	if (tmp) {
		ans *= 10;
		ans += tmp;
	}
	cout << ans << '\n';
	return 0;
}