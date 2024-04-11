#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;
int n, a[MAXN];

int main () {
	n = read(); int i, j, k;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n - 2; i++) if (a[i] > (a[i + 1] ^ a[i + 2])) { puts("1"); return 0; }
	for (i = 1; i <= n; i++) a[i] ^= a[i - 1];
	int ans = 1e9 + 7;
	for (i = 1; i <= n; i++) for (j = i; j <= n; j++) for (k = j + 1; k <= n; k++)
		if ((a[i - 1] ^ a[j]) > (a[j] ^ a[k]))
			ans = min(ans, j - i + k - (j + 1));
	if (ans > 1e9) puts("-1");
	else printf("%d\n", ans);
	return 0;
}