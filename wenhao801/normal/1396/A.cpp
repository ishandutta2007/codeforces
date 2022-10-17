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

#define ll long long
int n, a[100100];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	if (n == 1) { printf("1 1\n%d\n1 1\n0\n1 1\n0\n", -a[1]); return 0; }
	printf("%d %d\n", 1, n);
	for (i = 1; i <= n; i++) printf("%lld ", -1ll * a[i] * n);
	printf("\n%d %d\n", 1, n - 1);
	for (i = 1; i < n; i++) printf("%lld ", 1ll * a[i] * (n - 1));
	printf("\n%d %d\n%lld\n", n, n, 1ll * (n - 1) * a[n]);
	return 0;
}