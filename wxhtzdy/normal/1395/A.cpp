#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		bool ok = 0;
		for (int i = 0; i < 3; i++) {
			int cnt = a % 2 + b % 2 + c % 2 + d % 2;
			if (cnt < 2) {
				ok = 1;
				break;
			}
			if (a > 0 && b > 0 && c > 0) {
				--a; --b; --c; ++d;
			}
		}
		if (ok) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}
}