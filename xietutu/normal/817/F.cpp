#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M = 1000000000000000001LL;
const int maxn = 100010;
int n, TC, value;
LL st, ed; 
struct node {
	int ch[2];
	char inv, v;
} seg[maxn * 200];
inline void flip(int tot) {
	if (seg[tot].v != 3) {
		seg[tot].v = 3 - seg[tot].v;
	}
	else seg[tot].inv = 1 - seg[tot].inv;
}
inline void setv(int tot, int value) {
	seg[tot].inv = 0;
	seg[tot].v = value;
}
inline void down(int tot) {
	for (int i = 0; i < 2; ++i) {
		if (!seg[tot].ch[i]) {
			seg[tot].ch[i] = ++TC;
		}
		if (seg[tot].v != 3) {
			setv(seg[tot].ch[i], seg[tot].v);
		}
		if (seg[tot].inv) {
			flip(seg[tot].ch[i]);
		}
	}
	seg[tot].inv = 0;
}
inline void update(int tot) {
	int lson = seg[tot].ch[0], rson = seg[tot].ch[1];
	if (seg[lson].v == 3 || seg[rson].v == 3 || seg[lson].v != seg[rson].v) {
		seg[tot].v = 3;
	}
	else {
		seg[tot].v = seg[lson].v;
	}
}
void modify(int tot, LL l, LL r) {
	if (st <= l && r <= ed) {
		setv(tot, value);
		return;
	}
	down(tot);
	LL mid = (l + r) / 2;
	if (st <= mid) modify(seg[tot].ch[0], l, mid);
	if (mid < ed) modify(seg[tot].ch[1], mid + 1, r);
	update(tot);
}
void invert(int tot, LL l, LL r) {
	if (st <= l && r <= ed) {
		flip(tot);
		return;
	}
	down(tot);
	LL mid = (l + r) / 2;
	if (st <= mid) invert(seg[tot].ch[0], l, mid);
	if (mid < ed) invert(seg[tot].ch[1], mid + 1, r);
	update(tot);
}
LL query(int tot, LL l, LL r) {
	if (seg[tot].v == 2) return l;
	down(tot);
	LL mid = (l + r) / 2;
	if (seg[seg[tot].ch[0]].v != 1) return query(seg[tot].ch[0], l, mid);
	else return query(seg[tot].ch[1], mid + 1, r); 
}
int main() {
	scanf("%d", &n);
	seg[0].v = 2; 
	for (int i = 1; i <= n; ++i) {
		int type;
		scanf("%d%I64d%I64d", &type, &st, &ed);
		if (type != 3) {
			value = type;
			modify(0, 1, M);
		}
		else invert(0, 1, M);
		printf("%I64d\n", query(0, 1, M));
	}
}