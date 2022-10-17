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

int n, m; char a[1010][1010];

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read();
		int i, j;
		for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
		if (m & 1) { puts("YES");  for (i = 1; i <= (m >> 1); i++) printf("1 2 "); puts("1 2"); continue; }
		bool fin = 0;
		for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) {
			if (fin) break;
			if (a[i][j] == a[j][i]) { puts("YES"); for (int k = 1; k <= (m >> 1); k++) printf("%d %d ", i, j); printf("%d\n", i);
			fin = 1; }
			if (fin) break;
		}
		if (!fin) {
			for (i = 1; i <= n; i++) {
				int pos0 = -1, pos1 = -1;
				for (j = 1; j <= n; j++) if (j != i) {
					if (a[i][j] == 'a') pos0 = j;
					if (a[i][j] == 'b') pos1 = j;
				}
				if (pos0 != -1 && pos1 != -1) {
					fin = 1; puts("YES");
					int x = pos0, y = i, z = pos1;
					if ((m >> 1) & 1) {
						m >>= 1; printf("%d %d %d", x, y, z);
						--m; m >>= 1; while (m--) printf(" %d %d %d %d", y, x, y, z);
						puts("");
					}
					else {
						m >>= 2; printf("%d %d %d %d %d", y, x, y, z, y);
						--m; while (m--) printf(" %d %d %d %d", x, y, z, y);
						puts("");
					}
					break;
				}
			}
			if (!fin ) puts("NO");
		}
	}
	return 0;
}