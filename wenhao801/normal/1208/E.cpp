#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

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

const int MAXN = 1001000;
int n, w, d[MAXN];
void add (int l, int r, int k) { d[l] += k, d[r + 1] -= k; }

int tmp[MAXN], t[MAXN << 2];
void build (int l, int r, int x) {
	t[x] = -1e9 - 7; if (l ==r) return;
	int mid = (l + r) >> 1;
	build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
}
void modify(int l, int r,  int k,int L, int R, int x) {
	if (l <= L && R <= r) {t[x] = max(t[x], k);return; }
	int mid = (L + R) >>1 ;
	if (l <= mid) modify(l, r, k, L, mid, x << 1);

	if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);

}
int query (int pos, int l, int r, int x) {
	if (l == r) return t[x];
	int mid = (l + r) >> 1;
	if (pos <= mid) return max(t[x], query(pos, l, mid, x << 1)); else return max(t[x], query(pos, mid + 1, r, x << 1 | 1));
}

signed main () {
	n = read(), w = read(); int i, j;
	while (n--) {
		int L = read();
		for (i = 1; i <= L; i++) tmp[i] = read();
		if (L * 2 < w) {
			int suf = 0;
			for (i = 1; i <= L; i++) suf = max(suf, tmp[L - i + 1]), add(w - i + 1, w - i + 1, suf);
			for (i = 1; i <= L; i++) tmp[i] = max(tmp[i], tmp[i - 1]), add(i, i, tmp[i]);
			add(L + 1, w - L, tmp[L]);
		}
		else {
			build(1, w, 1);
			if (L != w) modify(1, w - L, 0, 1, w, 1), modify(L + 1, w, 0, 1, w, 1);
			for (i = 1; i <= L; i++) modify(i, min(w, i + (w - L)), tmp[i], 1, w, 1);
			for (i = 1; i <= w; i++) add(i, i, query(i, 1, w, 1));
		}
	}
	for (i = 1; i <= w; i++) d[i] += d[i - 1], cout << d[i] << ' ';
	return 0;
}