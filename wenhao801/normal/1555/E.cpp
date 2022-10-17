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

const int MAXN = 4004000;
int t[MAXN], tag[MAXN], n, m;

struct seg { int l, r, w; bool operator < (const seg &tmp) const { return w < tmp.w; } } a[MAXN];
void pushup (int x) { t[x] = min(t[x << 1], t[x << 1 | 1]) ;}
void cover (int x, int k) { t[x] += k, tag[x] += k;  }
void pushdown (int x) {
	if (tag[x]) { cover(x << 1, tag[x]), cover(x << 1 | 1, tag[x]), tag[x] = 0; }
}
void modify (int l, int r, int k, int L, int R, int x) {
	if (l <= L && R <= r) { cover(x, k); return; }
	int mid = (L + R) >> 1; pushdown(x);
	if (l <= mid) modify(l, r, k , L, mid, x << 1);
	if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);
	pushup(x);
}

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= n; i++) a[i].l = read(), a[i].r = read() - 1, a[i].w = read();
	sort(a + 1, a + n + 1);
	int ans = 1e9 + 7;
	for (i = 1, j = 0; i <= n; i++) {
		while (j < n && !t[1]) ++j, modify(a[j].l, a[j].r, 1, 1, m - 1, 1);
		if (t[1]) ans = min(ans, a[j].w - a[i].w); else break;
		modify(a[i].l, a[i].r, -1, 1, m - 1, 1);
	}
	printf("%d\n", ans);
	return 0;
}