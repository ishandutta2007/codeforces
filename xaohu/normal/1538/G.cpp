#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T;
long long x, y, a, b;

void solve() {
	cin >> x >> y >> a >> b;
	if (a == b) 
		return cout << min(x, y) / a << endl, void(0);
	if (a < b) swap(a, b);
	int l = 0, r = 1e9;
	while (l < r) {
		int m = (l + r + 1) / 2;
		double R = min(1.0 * m, floor((double)(x - b * m) / (a - b)));
		double L = max(0.0, ceil((double)(y - a * m) / (b - a)));
		if (L <= R)
			l = m;
		else
			r = m - 1;
	}
	cout << l << endl;
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}