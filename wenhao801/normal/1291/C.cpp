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

int n, m, k;
int a[4040] = {};

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read(), k = read();
		int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		k = min(k, m - 1);
		int ans = 0;
		for (i = 0; i <= k; i++) {
			int l = i + 1, r = n - (k - i);
			int Min = 1e9 + 7;
			for (j = 0; j <= m - 1 - k; j++) {
				int L = l + j, R = r - (m - 1 - k - j);
				//printf("%d %d %d %d\n", l, r, L, R);
				Min = min(Min, max(a[L], a[R]));
			}
			ans = max(ans, Min);
		}
		printf("%d\n", ans);
	}
	return 0;
}