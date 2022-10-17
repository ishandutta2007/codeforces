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

const int MAXN = 300300;
int t[MAXN << 2][22], a[MAXN], n;
void pushup (int ret[22], int x[22], int y[22]) {
	int i, j, tmp[22] = {};
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) if ((x[i] >> j) & 1)
			tmp[i] |= y[j];
	}
	for (i = 0; i < 20; i++) ret[i] = tmp[i];
}
void build (int l, int r, int x) {
	if (l == r) {
		int i = read(), j; a[l] = i;
		for (j = 0; j < 20; j++) {
			t[x][j] = 1 << j;
			if ((i >> j) & 1) t[x][j] |= i;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
	pushup(t[x], t[x << 1], t[x << 1 | 1]);
}
int now;
void query (int l, int r, int L, int R, int x) {
	if (l <= L && R <= r) {
		int ret = now, i;
		for (i = 0; i < 20; i++) if ((now >> i) & 1) ret |= t[x][i];
		now = ret; return;
	}
	int mid = (L + R) >> 1;
	if (l <= mid) query(l,r, L, mid, x << 1);
	if (mid < r) query(l, r, mid + 1, R, x << 1 | 1);
}

int main () {
	n = read(); int m = read();
	build(1, n, 1);
	while (m--) {
		int l = read(), r = read();
		if (r == l + 1) { puts((a[l] & a[r]) ? "Shi" : "Fou"); continue; }
		now = a[l]; query(l + 1, r, 1, n, 1); puts((now & a[r]) ? "Shi" : "Fou");
	}
	return 0;
}