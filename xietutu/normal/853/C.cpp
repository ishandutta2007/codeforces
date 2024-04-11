#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
typedef long long LL;
int TC, n, q, st, ed;
struct node {
	node *ch[2];
	int v;
} TS[maxn * 40], *seg[maxn];
node* build(int l, int r) {
	node* now = TS + (TC++);
	if (l == r) return now;
	int mid = (l + r) / 2;
	now->ch[0] = build(l, mid);
	now->ch[1] = build(mid + 1, r);
	return now;
}
node* modify(int l, int r, node* pre, int pos) {
	TS[TC] = *pre;
	node* now = TS + (TC++);
	++now->v;
	if (l == r) {
		return now;
	}
	int mid = (l + r) / 2;
	if (pos <= mid) now->ch[0] = modify(l, mid, pre->ch[0], pos);
	if (mid < pos) now->ch[1] = modify(mid + 1, r, pre->ch[1], pos);
	return now;
}
inline int query(int l, int r, node* ls, node* rs) {
	if (st <= l && r <= ed) 
		return rs->v - ls->v;
	int mid = (l + r) / 2, ret = 0;
	if (st <= mid) ret += query(l, mid, ls->ch[0], rs->ch[0]);
	if (mid < ed) ret += query(mid + 1, r, ls->ch[1], rs->ch[1]);
	return ret;
}
inline LL calc(int n) { return 1LL * n * (n - 1) / 2;}
int main() {
	scanf("%d%d", &n, &q);
	seg[0] = build(1, n);
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		seg[i] = modify(1, n, seg[i - 1], p);
	}
	for (int i = 1; i <= q; ++i) {
		int l, d, r, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		LL ret = calc(l - 1) + calc(n - r) + calc(d - 1) + calc(n - u);
		if (d > 1) {
			st = 1; ed = d - 1;
			if (l > 1) ret -= calc(query(1, n, seg[0], seg[l - 1]));
			if (r < n) ret -= calc(query(1, n, seg[r], seg[n]));
		}
		if (u < n) {
			st = u + 1; ed = n;
			if (l > 1) ret -= calc(query(1, n, seg[0], seg[l - 1]));
			if (r < n) ret -= calc(query(1, n, seg[r], seg[n]));
		}
		printf("%I64d\n", calc(n) - ret);
	}
}