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

int n, a[110], u, v;

int main () {
	int T = read();
	while (T--) {
		n = read(), u = read(), v = read(); int i, j; bool fin = 0;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 2; i <= n; i++) if (abs(a[i] - a[i - 1]) > 1) { fin = 1; break; }
		if (fin) { puts("0"); continue; }
		int ans = v + min(u, v);
		for (i = 1; i <= n; i++) {
			bool f = 1;
			if (i > 1) f &= a[i] == a[i - 1];
			if (i < n) f &= a[i] == a[i + 1];
			if (f) ans = min(ans, v + min(u, v)); else ans = min(ans, min(u, v));
		}
		printf("%d\n", ans);
	}
	return 0;
}