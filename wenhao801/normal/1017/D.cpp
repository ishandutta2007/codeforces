#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

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
	while (c >= '0' && c <= '9') ret = ret * 2 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair<int, int>
int n, m, q, a[13], pre[1 << 12], buc[1 << 12];

pii v[1 << 12][4400]; int top[1 << 12];
bool cmp (pii x, pii y) { return x.second < y.second; }

int main () {
	cin >> n >> m >> q; int i, j;
	for (i = n - 1; i >= 0; i--) cin >> a[i];
	for (i = 1; i <= m; i++) ++buc[read()];
	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) pre[i] += ((i >> j) & 1) * a[j];
	}
	while (q--) {
		int x = read(); int lim; scanf("%d", &lim);
		if (!top[x]) {
			for (i = 0; i < (1 << n); i++) if (buc[i]) ++top[x], v[x][top[x]] = make_pair(buc[i], pre[(1 << n) - 1 - (x ^ i)]);
			sort(v[x] + 1, v[x] + top[x] + 1, cmp);
			for (i = 1; i <= top[x]; i++) v[x][i].first += v[x][i - 1].first;
		}
		int L = 1, R = top[x], res = 0;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (v[x][mid].second <= lim) res = mid, L = mid + 1; else R = mid - 1;
		}
		printf("%d\n", v[x][res].first);
	}
	return 0;
}