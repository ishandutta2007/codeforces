#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		if (xa > xb) swap(xa, xb);
		if (ya > yb) swap(ya, yb);
		int ans = abs(xa - xb) + abs(ya - yb);
		if (xa == xb && xb == xf && ya <= yf && yf <= yb) ans += 2;
		if (ya == yb && yb == yf && xa <= xf && xf <= xb) ans += 2;
		cout << ans << '\n';
	}
	return 0;
}