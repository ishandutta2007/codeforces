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
int a[MAXN];
int main () {
	int T = read();
	while (T--) {
		int n = read(), i;
		for (i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		long long ans = 0, tmp = 0;
		for (i = 1; i <= n; i++) ans += a[i] - a[i - 1], ans -= 1ll * (i - 1) * a[i] - tmp, tmp += a[i];
		cout << ans << endl;
	}
	return 0;
}