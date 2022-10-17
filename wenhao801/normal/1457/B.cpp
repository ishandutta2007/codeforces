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

int n, k, a[100100], f[100100][110];
int las[100100];
int main () {
	int t = read();
	while (t--) {
		n = read(), k = read();
		int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i++) {
			if (a[i] != a[i - 1]) las[i] = i - 1;
			else las[i] = las[i - 1];
		}
		for (i = 0; i <= n; i++) for (j = 1; j <= 100; j++) f[i][j] =0 ;
		int ans = n + 1;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= 100; j++) {
				if (a[i] == j) f[i][j] = f[las[i]][j];
				else f[i][j] = f[max(0, i - k)][j] + 1;
				if (i == n) ans = min(ans, f[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}