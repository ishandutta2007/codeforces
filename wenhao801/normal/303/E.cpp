#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second
#define vd vector <double>
#define size(v) (int(v.size()))

const int MAXN = 88;
pii a[MAXN]; int b[MAXN << 1], top, n;

double ans[MAXN][MAXN];

int L, R;
void solve (int l, int r, double cur[MAXN][MAXN]) {
	if (l == r) {
		if (a[l].se <= L || a[l].fr >= R) return;
		for (int i = 0; i < n; i++) for (int j = 0; i + j < n; j++)
			ans[l][i] += cur[i][j] * (R - L) / (a[l].se - a[l].fr) / (j + 1),
			ans[l][i + j + 1] -= cur[i][j] * (R - L) / (a[l].se - a[l].fr) / (j + 1);
		return;
	}
	double nexl[2][MAXN][MAXN] = {}, nexr[2][MAXN][MAXN] = {}; int mid = (l + r) >> 1;
	for (int i = 0; i < n; i++) for (int j = 0; i + j < n; j++) nexl[1 ^ (l & 1)][i][j] = nexr[mid & 1][i][j] = cur[i][j];
	for (int i = l; i <= mid; i++) {
		int now = i & 1, las = now ^ 1;
		for (int j = 0; j < n; j++) for (int k = 0; j + k < n; k++) {
			nexl[now][j][k] = nexl[las][j][k] * min(1.0, 1.0 * max(a[i].se - R, 0) / (a[i].se - a[i].fr));
			if (j) nexl[now][j][k] += nexl[las][j - 1][k] * min(1.0, 1.0 * max(L - a[i].fr, 0) / (a[i].se - a[i].fr));
			if (k && a[i].fr <= L && a[i].se >= R) nexl[now][j][k] += nexl[las][j][k - 1] * (R - L) / (a[i].se - a[i].fr);
		}
	}
	solve(mid + 1, r, nexl[mid & 1]);
	for (int i = mid + 1; i <= r; i++) {
		int now = i & 1, las = now ^ 1;
		for (int j = 0; j < n; j++) for (int k = 0; j + k < n; k++) {
			nexr[now][j][k] = nexr[las][j][k] * min(1.0, 1.0 * max(a[i].se - R, 0) / (a[i].se - a[i].fr));
			if (j) nexr[now][j][k] += nexr[las][j - 1][k] * min(1.0, 1.0 * max(L - a[i].fr, 0) / (a[i].se - a[i].fr));
			if (k && a[i].fr <= L && a[i].se >= R) nexr[now][j][k] += nexr[las][j][k - 1] * (R - L) / (a[i].se - a[i].fr);
		}
	}
	solve(l, mid, nexr[r & 1]);
}

int main () {
	n = read(); int i, j, k;
	for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read(), b[++top] = a[i].fr, b[++top] = a[i].se;
	sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
	double tmp[MAXN][MAXN] = {}; tmp[0][0] = 1;
	for (int it = 1; it < top; it++) {
		L = b[it], R = b[it + 1];
		solve(1, n, tmp);
	}
	for (i = 1; i <= n; i++, putchar('\n')) for (j = 1; j <= n; ans[i][j] += ans[i][j - 1], j++) printf("%.8lf ", ans[i][j - 1]);
	return 0;
}