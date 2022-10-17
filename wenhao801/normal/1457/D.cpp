#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
int a[100100];
int highbit (int x) { return log2(x); }

int main () {
	int n = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n - 2; i++) {
		if (highbit(a[i]) == highbit(a[i + 1]) && highbit(a[i + 1]) == highbit(a[i + 2])) {
			puts("1"); return 0;
		}
	}
	for (i = 1; i <= n; i++) a[i] ^= a[i - 1];
	int ans = 998244353;
	for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) {
		for (int k = j; k < n; k++) for (int l = k + 1; l <= n; l++) {
			if ((a[i] ^ a[j]) > (a[k] ^ a[l])) ans = min(ans, j - i - 1 + l - k - 1);
		}
	}
	if (ans == 998244353) puts("-1"); else 
	printf("%d\n", ans);
	return 0;
}