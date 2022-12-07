#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, n, l, r, a[222111]; 
 
void solve() {
	cin >> n >> l >> r;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long res = 0;
	rep(i, 1, n) {
		int x = lower_bound(a + 1, a + n + 1, l - a[i]) - a;
		int y = upper_bound(a + 1, a + n + 1, r - a[i]) - a;
		if (x <= y)
			res += y - x;
		if (l <= 2 * a[i] && 2 * a[i] <= r)
			res--;
	}
	cout << res / 2 << endl;
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}