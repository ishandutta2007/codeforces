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

using ll = long long;
const int MAXN = 100100;
int n, p, K; char a[MAXN]; int x, y;
ll f[MAXN];

int main () {
	int T = read(); while (T--) {
		n = read(), p = read(), K = read(); int i, j;
		scanf("%s", a + 1);
		x = read(), y = read();
		ll ans = 1e18;
		for (i = n; i >= 1; i--) {
			f[i] = a[i] == '0' ? x : 0;
			if (i + K <= n) f[i] += f[i + K];
			if (i >= p) ans = min(ans, f[i] + 1ll * (i - p) * y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}