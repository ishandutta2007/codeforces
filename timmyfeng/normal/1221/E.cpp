#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	string s;
	cin >> a >> b >> s;
	s.push_back('X');

	int len = 0, cnt = 0, spec = 0;
	for (auto i : s) {
		if (i == '.') {
			++len;
		} else {
			if (len >= b && len < a) {
				cout << "NO" << '\n';
				return;
			} else if (len >= 2 * b) {
				if (spec) {
					cout << "NO" << '\n';
					return;
				}
				spec = len;
			} else if (len >= a && len < 2 * b) {
				++cnt;
			}
			len = 0;
		}
	}
	
	if (!spec) {
		cout << (cnt % 2 ? "YES" : "NO") << '\n';
		return;
	}
	for (int i = 0; i <= spec - a; ++i) {
		int j = spec - a - i;
		if ((i >= b && i < a) || (i >= 2 * b)) continue;
		if ((j >= b && j < a) || (j >= 2 * b)) continue;
		if ((cnt + (i >= a) + (j >= a)) % 2 == 0) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}