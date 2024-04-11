#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

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

int askand (int u, int v) { printf("and %d %d\n", u, v); fflush(stdout); int res = read(); return res; }
int askor (int u, int v) { printf("or %d %d\n", u, v); fflush(stdout); int res = read(); return res; }

int n, K, ans[100010];

int main () {
	n = read(), K = read();
	int i, j;
	ll a12 = askand(1, 2), o12 = askor(1, 2), a13 = askand(1, 3), o13 = askor(1, 3), a23 = askand(2, 3), o23 = askor(2, 3);
	ll s = a12 + o12 + a13 + o13 + a23 + o23; s >>= 1;
	int c = s - a12 - o12, b = s - a13 - o13, a = s - a23 - o23;
	ans[1] = a, ans[2] = b, ans[3] = c;
	for (int i = 4; i <= n; i++) {
		ans[i] = 1ll * askand(1, i) + askor(1, i) - a;
	}
	sort(ans + 1, ans + n + 1);
	printf("finish %d\n", ans[K]);
	return 0;
}