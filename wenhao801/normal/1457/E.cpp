#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define ll long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 500500;
int n, k, a[MAXN];

int main () {
	n = read(), k = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	ll ans = 0, tmp = 0;
	for (i = n; i >= 1; i--) {
		ans += tmp;
		tmp += a[i];
		if (tmp < 0) { a[i] = tmp; break; }
	}
	for (i; i >= 1; i--) ans += 1ll * a[i] * ((i - 1) / (k + 1));
	printf("%lld\n", ans);
	return 0;
}