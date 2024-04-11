#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int l, r;
		long long m;
		cin >> l >> r >> m;

		int a = 0;
		int b = 0;
		int c = 0;
		for (int i = l; i <= r; ++i) {
			if (m % i == 0) {
				a = i;
				b = l;
				c = l;
				break;
			}

			if (i - (m % i) <= r - l) {
				a = i;
				b = l;
				c = l + i - (m % i);
				break;
			}

			if (i <= m) {
				if (m % i <= r - l) {
					a = i;
					b = l + m % i;
					c = l;
					break;
				}
			}
		}
		cout << a <<  " " << b << " " << c << "\n";
	}
}