#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MAX = 16000000;

int xl, xr, yl, yr, zl, zr, n, m, k, xm, ym, zm;

int L[MAX], R[MAX], rt[N * 4], ch[MAX][2], x, y, z, sz, Rt;

#define lc (ch[p][0])
#define rc (ch[p][1])

void add2(int &p, int l, int r, int y, int z) {
	if(!p) {
		p = ++ sz;
		R[p] = zm + 1;
	}
	if(z <= zr) L[p] = max(L[p], z);
	if(z >= zl) R[p] = min(R[p], z);
	if(l == r) return;
	int mid = (l + r) >> 1;
	
	if(y > mid) add2(rc, mid + 1, r, y, z);
	else add2(lc, l, mid, y, z);
}

void add(int p, int l, int r, int x, int y, int z) {
	add2(rt[p], 1, ym, y, z);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(x > mid) add(p << 1 | 1, mid + 1, r, x, y, z);
	else add(p << 1, l, mid, x, y, z);
}

int query2(int p, int l, int r, int yl, int yr, int zl, int zr) {
	if(!p) return 0;
	if(l == yl && r == yr) {
		if(zl > L[p] && zr < R[p]) return 0;
		return 1;
	}
	int mid = (l + r) >> 1;
	if(yl > mid) return query2(rc, mid + 1, r, yl, yr, zl, zr);
	else if(yr <= mid) return query2(lc, l, mid, yl, yr, zl, zr);
	else return query2(lc, l, mid, yl, mid, zl, zr) | query2(rc, mid + 1, r, mid + 1, yr, zl, zr);
}

int query(int p, int l, int r, int xl, int xr, int yl, int yr, int zl, int zr) {
	int mid = (l + r) >> 1;
	if(l == xl && r == xr) {
		return query2(rt[p], 1, ym, yl, yr, zl, zr);
	}
	if(xl > mid) return query(p << 1 | 1, mid + 1, r, xl, xr, yl, yr, zl, zr);
	else if(xr <= mid) return query(p << 1, l, mid, xl, xr, yl, yr, zl, zr);
	else return query(p << 1, l, mid, xl, mid, yl, yr, zl, zr) | query(p << 1 | 1, mid + 1, r, mid + 1, xr, yl, yr, zl, zr);
} 

main(void) {
	scanf("%d%d%d%d%d%d", &xm, &ym, &zm, &n, &m, &k);
	xl = xm;
	yl = ym;
	zl = zm;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &x, &y, &z);
		xl = min(xl, x);
		yl = min(yl, y);
		zl = min(zl, z);
		zr = max(zr, z);
		yr = max(yr, y);
		xr = max(xr, x);
	}
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d%d", &x, &y, &z);
		if(x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
			puts("INCORRECT");
			return 0;
		}
		add(1, 1, xm, x, y, z);
	}
	puts("CORRECT");
	for(int i = 1; i <= k; ++ i) {
		scanf("%d%d%d", &x, &y, &z);
		if(x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
			puts("OPEN");
			continue;
		}
		else {
			int Xl = min(xl, x), Xr = max(xr, x), Yl = min(yl, y), Yr = max(yr, y), Zl = min(zl, z), Zr = max(zr, z);
			int now = query(1, 1, xm, Xl, Xr, Yl, Yr, Zl, Zr);
			if(now) puts("CLOSED");
			else puts("UNKNOWN");
		}
	}
}