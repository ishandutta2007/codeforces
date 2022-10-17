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
}const long long inf = 1e18;

int main () {
	int T = read();
	while (T--) {
		long long W = read(), H = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read(), w = read(), h = read();
		long long ans = inf;
		if (x2 - x1 + w > W && y2 - y1 + h > H) { puts("-1"); continue; }
		if (x2 - x1 + w <= W) ans = min(ans, min(max(0ll, w - x1), max(0ll, w - (W - x2))));
		if (y2 - y1 + h <= H) ans = min(ans, min(max(0ll, h - y1), max(0ll, h - (H - y2))));
		printf("%lld.00000000\n", ans);
	}
	return 0;
}