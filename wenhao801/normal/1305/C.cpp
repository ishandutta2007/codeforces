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

int n, m;
int a[1010] = {};

int main () {
	n = read(), m = read();
	if (n > m) { puts("0"); return 0; }
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	int ans = 1;
	for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) ans = ans * (long long)(abs(a[i] - a[j])) % m;
	printf("%d\n", ans);
	return 0;
}