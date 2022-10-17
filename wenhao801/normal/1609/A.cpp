#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
#define ll long long

int main () {
	int T = read();
	while (T--) {
		int n = read(); ll a[22];
		int i, j; ll mx = 0; ll cur = 1; for (i = 1; i <= n; i++) {
			a[i] = read();
			while (a[i] % 2 == 0) cur <<= 1, a[i] >>= 1;
			mx = max(mx, a[i]);
		}
		ll ans = 0;
		for (i = 1; i <= n; i++) {
			if (a[i] == mx) ans += cur * mx, mx = 0;
			else ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}