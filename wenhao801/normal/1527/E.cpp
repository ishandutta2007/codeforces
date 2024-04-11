#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

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

const int MAXN = 40040;
int n, K, a[MAXN];
ll f[2][MAXN], mn[MAXN]; int cur[MAXN];

ll t[MAXN << 2], tag[MAXN << 2];
void pushup (int x) { t[x] = min(t[x << 1], t[x << 1 | 1]); }
void build (int l, int r, int x) {
	tag[x] = 0;
	if (l == r){ 
		tag[x] = 0, t[x] = l == 1 ? 0 : 1e18;
		return;
	}
	int mid = (l + r) >> 1;
	build( l, mid, x <<1); build( mid + 1, r, x <<1 | 1);
	pushup(x);
}
void cover (int x, ll k) { t[x] += k, tag[x] += k; }
void pushdown (int x) { if (tag[x]) cover(x << 1, tag[x]), cover(x << 1 | 1, tag[x]), tag[x] = 0; }
void modify (int l, int r, ll k, int L, int R, int x) {
	if (l <= L && R <= r) { cover(x, k); return; }
	int mid= (L + R) >> 1; pushdown(x);
	if (l <= mid) modify(l, r, k, L, mid, x << 1); 
	if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);
	pushup(x);
}

int main () {
	n = read(), K = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) f[0][i] = 1e18;
	for (i = 1; i <= K; i++) {
		build(1, n, 1);
		int now = i & 1, las = now ^ 1;
		for (j = 1; j <= n; j++) cur[j] = 0, mn[j] = 1e18;
		 mn[a[1]] = 0, cur[a[1]] = 1;
		for (j = 1; j <= n; j++) {
			f[now][j] = t[1];
			if (j == n) break;
			if (!cur[a[j + 1]]) {
				cur[a[j + 1]] = j + 1;
				mn[a[j + 1]] = 	f[las][j] - (j + 1);
				modify(j + 1, j + 1, -1e18, 1, n, 1);
				modify(j + 1, j + 1, f[las][j], 1, n, 1);

			}
			else {
				modify(1, cur[a[j + 1]], j + 1 - cur[a[j + 1]], 1, n, 1);
				mn[a[j + 1]] = min(mn[a[j + 1]], f[las][j] - (j + 1));
				cur[a[j + 1]] = j + 1;
				modify(j + 1, j + 1, -1e18, 1, n, 1);
				modify(j + 1, j + 1, f[las][j], 1, n, 1);
			}
		}
		// for (j = 1; j <= n; j++) cout << f[now][j] << ' ';
		// cout << endl;
	}
	printf("%lld\n", f[K & 1][n]);
	return 0;
}