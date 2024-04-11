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
int n, m, p;
int a[1001000];
int b[1001000];
int main () {
	n = read(), m = read(), p = read();
	int i, j;
	for (i = 0; i < n; i++) a[i] = read();
	for (i = 0; i < m; i++) b[i] = read();
	int T = min(n, m);
	for (i = 0; i < T; i++) {
		if (a[i] % p && b[i] % p) { printf("%d\n", i * 2); return 0; }
		else if (a[i] % p) {
			for (j = i + 1; b[j] % p == 0; j++);
			printf("%d\n", j + i);
			return 0;
		}
		else if (b[i] % p) {
			for (j = i + 1; a[j] % p == 0; j++);
			printf("%d\n", j + i);
			return 0;
		}
	}
	return 0;
}