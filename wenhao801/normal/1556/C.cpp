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
const int MAXN = 100100;
int n, a[MAXN]; ll s[MAXN];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read(), s[i] = s[i - 1] + ((i & 1) ? a[i] : -a[i]);
	ll ans = -(n / 2);
	for (i = 1; i <= n; i += 2) {
		ll pre = 0;
		for (j = i + 1; j <= n; j += 2) {
			if (a[i] < -pre) break;
			int tmp = a[i] + pre; ll qwq = s[j - 1] - s[i] - pre;
			// printf("%d %d: L = %d, sum = %lld\n", i, j, tmp, qwq);
			if (a[j] >= qwq) {
				int tmp2 = a[j] - qwq;
				ans += min(tmp, tmp2) + 1;
			}
			pre = min(pre, s[j] - s[i]);
			// cout << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}