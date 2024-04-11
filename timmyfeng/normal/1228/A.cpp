#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l, r;
	cin >> l >> r;
	for (int i =l; i <= r; ++i) {
		int tmp = i;
		bool ok = true;
		int used = 0;
		while (tmp) {
			if (used & (1 << (tmp % 10))) {
				ok = false;
			}
			used |= 1 << (tmp % 10);
			tmp /= 10;
		}
		if (ok) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}