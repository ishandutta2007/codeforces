#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, l, r;

void solve() {
	cin >> l >> r;
	long long res = 0;
	while (l < r) {
		res += r - l;
		l /= 10;
		r /= 10;
	}
	cout << res << endl;
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}