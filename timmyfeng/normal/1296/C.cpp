#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		map<pair<int, int>, int> prev;
		int n;
		string s;
		cin >> n >> s;
		int x = 0, y = 0, l = -1, r = 1e9;
		for (int i = 0; i < n; ++i) {
			prev[{x, y}] = i;
			if (s[i] == 'L') {
				--x;
			} else if (s[i] == 'R') {
				++x;
			} else if (s[i] == 'U') {
				++y;
			} else {
				--y;
			}
			if (prev.count({x, y})) {
				if (i - prev[{x, y}] < r - l) {
					l = prev[{x, y}];
					r = i;
				}
			}
		}
		if (l == -1) {
			cout << -1 << '\n';
		} else 
			cout << l + 1 << ' ' << r + 1 << '\n';
	}
}