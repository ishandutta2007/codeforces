#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int mxdiff = -2e9, mxblow = -1e9;
		while (n--) {
			int d, h;
			cin >> d >> h;
			mxdiff = max(mxdiff, d - h);
			mxblow = max(mxblow, d);
		}
		if (mxblow >= x) {
			cout << 1 << '\n';
		} else if (mxdiff <= 0) {
			cout << -1 << '\n';
		} else {
			cout << (x - mxblow - 1) / mxdiff + 2 << '\n';
		}
	}
}