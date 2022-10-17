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

const int MAXN = 200200;
int n, K, a[MAXN], b[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(), K = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = b[i] = read();
		sort(b + 1, b + n + 1);
		int ansl = 1, ansr = n;
		i = 1, j = 0; while (2 * j < n + K) ++j;
		while (j <= n) {
			if (b[j] - b[i] <= ansr - ansl) ansl = b[i], ansr = b[j];
			++i, ++j;
		}
		printf("%d %d\n", ansl, ansr);
		int last = 0, cur = 0;
		for (i = 1, j = K - 1; i <= n; i++) {
			if (a[i] >= ansl && a[i] <= ansr) ++cur; else --cur;
			if (cur > 0 && j) { --j; printf("%d %d\n", last + 1, i); last = i; cur = 0; }
		}
		printf("%d %d\n", last + 1, n);
	}
	return 0;
}