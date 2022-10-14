#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int cnt = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < x; i++) {
		int c = (int) (s[i] - '0');
		if (i == y) {
			cnt += 1 - c;
		} else {
			cnt += c;
		}
	}
	cout << cnt << '\n';
	return 0;
}