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

int a[333][333];

int main () {
	int T = read();
	while (T--) {
		int n = read(), m = read(); int i, j;
		for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) a[i][j] = read();
		bool done = 0;
		for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) if (a[i][j] > 4 - (i == 1 || i == n) - (j == 1 || j == m)) done = 1;
		if (done) puts("NO"); else {
			puts("YES");
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) { printf("%d ", 4 - (i == 1 || i == n) - (j == 1 || j == m)); }
				puts("");
			}
		}
	}
	return 0;
}