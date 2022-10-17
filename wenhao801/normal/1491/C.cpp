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

const int MAXN = 5050;
int n, a[MAXN], d[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read(), d[i] = 0;
		d[n + 1] = 0;
		long long ans = 0;
		for (i = 1; i <= n; i++) {
			d[i] += d[i - 1]; d[i + 2]++, d[min(n + 1, i + a[i] + 1)]--; a[i] -= d[i];
			if (a[i] < 1) d[i + 1] += 1 - a[i], d[i + 2] -= 1 - a[i];
			else ans += a[i] - 1;
		}
		cout << ans << endl;
	}
	return 0;
}