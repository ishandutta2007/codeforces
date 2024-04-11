#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
const int SQRT = 707;

int a[MX + 1];
int b[SQRT + 1][SQRT + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			for (int i = 1; i <= SQRT; ++i) {
				b[i][x % i] += y;
			}
		} else {
			if (x <= SQRT) {
				cout << b[x][y] << '\n';
			} else {
				int ans = 0;
				for (int i = y; i <= MX; i += x) {
					ans += a[i];
				}
				cout << ans << '\n';
			}
		}
	}
}