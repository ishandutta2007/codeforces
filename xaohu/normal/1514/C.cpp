#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int n, p = 1, ans;

int main() {
	cin >> n;
	rep(i, 1, n) {
		if (__gcd(i, n) == 1) {
			ans++;
			p = 1ll * p * i % n;
		}
	}
	if (p > 1) ans--;
	cout << ans << endl;
	rep(i, 1, n) {
		if (__gcd(i, n) == 1 && !(i > 1 && i == p)) {
			cout << i << " ";
		}
	}
	return 0;
}