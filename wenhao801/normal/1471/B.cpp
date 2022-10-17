#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
int a[7707700], k[7707700];

int main () {
	int T = read();
	while (T--) {
		int n = read(), x = read(); ll ans = 0;
		for (int i = 1; i <= n; i++) a[i] = read(), ans += a[i], k[i] = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] % x) break;
			ans += k[i] * a[i];
			++n; a[n] = a[i] / x, k[n] = k[i] * x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}