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

const int MAXN = 100100;
int n, q, a[MAXN];

int main () {
	n = read(), q = read();
	int i, j, cnt=  0;
	for (i = 1; i <= n; i++) a[i] = read(), cnt += a[i];
	while (q--) {
		int op = read(), x = read();
		if (op == 1) cnt -= a[x], a[x] ^= 1, cnt += a[x];
		else { putchar((x <= cnt) ? '1' : '0'); putchar('\n'); }
	}
	return 0;
}