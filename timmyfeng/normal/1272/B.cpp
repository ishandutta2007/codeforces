#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int u = 0, d = 0, l = 0, r = 0;
		for (auto i : s) {
			u += (i == 'U');
			d += (i == 'D');
			l += (i == 'L');
			r += (i == 'R');
		}

		u = d = min(u, d);
		l = r = min(l, r);
		if (!u && l) {
			l = r = 1;
		} else if (!l && u) {
			u = d = 1;
		}
		cout << l + r + u + d << '\n';
		cout << string(l, 'L') << string(u, 'U') << string(r, 'R') << string(d, 'D') << '\n';
	}
}