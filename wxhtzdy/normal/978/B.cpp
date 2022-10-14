#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') cnt++;
		else cnt = 0;
		if (cnt > 2) ans++;
	}
	cout << ans << '\n';
	return 0;
}