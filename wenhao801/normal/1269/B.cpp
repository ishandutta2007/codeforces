#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
#define int long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int a[2020], b[2020];
int t[2020] = {};

int min (int x, int y) { return x < y ? x : y;}

signed main () {
	int n = read(), m = read();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) b[i] = read();
	sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
	int ans = 1000000007;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)t[j] = a[j];
		int d = -t[i] + b[1]; if (d < 0) d = (d + m) % m;
		for (j = 1; j <= n; j++) t[j] = (t[j] + d) % m;
		sort(t + 1, t + n + 1);
		bool f = false; for (j = 1; j <= n; j++) if (t[j] != b[j]) { f= true; break; }
		if (!f) ans = min(ans, d);
	}
	cout << ans << endl;
	return 0;
}