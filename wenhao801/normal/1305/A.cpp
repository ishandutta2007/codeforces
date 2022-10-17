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

int n;
int a[101] = {};
int b[101] = {};

int main () {
	int T = read();
	while (T--) {
		n = read();
		int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i++) b[i] = read();
		sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
		for (i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
		for (i = 1; i <= n; i++) printf("%d ", b[i]); putchar('\n');
	}
	return 0;
}