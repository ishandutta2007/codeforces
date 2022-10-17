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

const int mod = 1e9 + 7;
int n, a, b, f[1001000];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) {
		int x = read();
		if (x == 1) ++a; else ++b;
	}
	f[0] = f[1] = 1;
	for (i = 2; i <= a; i++) f[i] = (1ll * (i - 1) * f[i - 2] + f[i - 1]) % mod;
	for (i = 0; i < b; i++) f[a] = 1ll * f[a] * (n - i) % mod;
	printf("%d\n", f[a]);
	return 0;
}