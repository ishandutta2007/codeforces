#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ld long double
const int MAXN = 100100;
const ld EPS = 1e-7;
ld a[MAXN], b[MAXN];

int main () {
	int n = read(), i, j; ld p = read();
	for (i = 1; i <= n; i++) a[i] = read(), b[i] = read();
	ld L = EPS, R = 1e18, ans = 2e18;
	while (R - L > EPS) {
		ld mid = (L + R) / 2, tmp = p;
		for (i = 1; i <= n; i++) if (a[i] * mid > b[i]) {
			tmp -= a[i] - b[i] / mid;
		}
		if (tmp < 0) R = mid - EPS;
		else L = mid + EPS, ans = mid;
	}
	if (ans > 9e17) puts("-1"); else cout << ans << endl;
	return 0;
}