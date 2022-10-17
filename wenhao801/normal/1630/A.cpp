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

int main () {
	int T = read();
	while (T--) {
		int n = read(), x = read();
		if (!x) { for (int i = 0; i < n / 2; i++) printf("%d %d\n", i, (n - 1) ^ i); continue; }
		if (x == n - 1) {
			if (n == 4) puts("-1"); else {
				int a = n - 1, b = n - 2, c = 1, d = 3, e = 0, f = (n - 1) ^ 3;
				printf("%d %d\n%d %d\n%d %d\n", a, b, c, d, e, f);
				for (int i = 0; i < n; i++) if (i != a && i != b && i != c && i != d && i != e && i != f && (i ^ (n - 1)) >= i)
					printf("%d %d\n", i, (n - 1) ^ i);
			}
			continue;
		}
		int y = n - 1, u = 0, v = y ^ x;
		printf("%d %d\n%d %d\n", x, y, u, v);
		for (int i = 0; i < n; i++) if (i != u && i != v && i != x && i != y && (i ^ (n - 1)) >= i)
			printf("%d %d\n", i, (n - 1) ^ i);
	}
	return 0;
}