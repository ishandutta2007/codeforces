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

const int MAXN = 202000;
int n, m, q;
int p[MAXN], a[MAXN];
int nex[MAXN][22], las[MAXN], ans[MAXN];

int main () {
	// freopen("test.in", "r", stdin);
	n = read(), m = read(), q = read();
	int i, j;
	for (i = 1; i <= n; i++) p[read()] = i;
	for (i = 1; i <= m; i++) a[i] = p[read()] - 1;
	for (i = 0; i <= 20; i++) nex[m + 1][i] = m + 1;
	for (i = m; i >= 1; i--) {
		if (!las[(a[i] + 1) % n]) nex[i][0] = m + 1;
		else nex[i][0] = las[(a[i] + 1) % n];
		las[a[i]] = i;
	}
	for (i = 1; i <= 20; i++) for (j = 1; j <= m; j++) nex[j][i] = nex[nex[j][i - 1]][i - 1];
	for (i = 1; i <= m; i++) {
		int cur = n - 1; ans[i] = i;
		for (j = 20; j >= 0; j--) if (cur >= (1 << j)) cur -= 1 << j, ans[i] = nex[ans[i]][j];
	}
	for (i = m - 1; i >= 1; i--) ans[i] = min(ans[i], ans[i + 1]);
	while (q--) {
		int l = read(), r = read();
		putchar('0' + (ans[l] <= r));
	}
	return 0;
}