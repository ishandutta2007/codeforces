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

const int MAXN = 200200;
int t[MAXN << 2];
void pushup (int x) { t[x] = t[x << 1] + t[x << 1 | 1]; }
void build (int l, int r, int x) {
	if (l == r) { t[x] = l; return; }
	int mid = (l + r) >> 1;
	build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
	pushup(x);
}

int n, s[MAXN], ans[MAXN];

int query (int k, int l, int r, int x) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if(t[x << 1] <= k) return query(k - t[x << 1], mid + 1, r, x << 1 | 1);
	else return query(k, l, mid, x << 1);
}
void modify (int pos, int l, int r, int x) {
	if (l == r) { t[x] = 0; return; }
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(pos, l, mid, x << 1); else modify(pos, mid + 1, r, x << 1 | 1);
pushup(x);}

signed main () {
	n = read(); int i, j;
	build(1, n,1 );
	for (i = 1; i <= n; i++) s[i] = read();
	for (i = n; i >= 1; i--) {
		int sum = s[i];
		ans[i] = query(sum, 1, n, 1);
		modify(ans[i],1, n,1);
	}
	for (i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}