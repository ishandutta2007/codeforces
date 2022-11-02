#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 200009;

int inv_mapx[MAX], inv_mapy[MAX];
bool seen_x[MAX];
int n, q;
int mx, my;

struct op {
	int x, y;
	char op;
	void set(int a, int b, char c) { x = a; y = b; op = c; }
}ops[MAX];

int treex[4 * MAX];
int lazyx[4 * MAX];
int treey[4 * MAX];
int lazyy[4 * MAX];
int *tree, *lazy;

inline int l(int i) { return (i << 1); }
inline int r(int i) { return l(i) + 1; }

void unlaze(int i, int from, int to) {
	if(lazy[i] == 0) return;
	tree[i] = max(tree[i], lazy[i]);
	if(from != to) {
		lazy[l(i)] = max(lazy[l(i)], lazy[i]);
		lazy[r(i)] = max(lazy[r(i)], lazy[i]);
	}
	lazy[i] = 0;
}

int query(int i, int from, int to, int x) {
	unlaze(i, from, to);
	if(from == to) return tree[i];
	int mid = (from + to) / 2;
	if(x <= mid) return query(l(i), from, mid, x);
	else return query(r(i), mid + 1, to, x);
}

void update(int i, int from, int to, int ul, int ur, int x) {
	if(from > ur || to < ul) return;
	unlaze(i, from, to);
	if(from >= ul && to <= ur) {
		tree[i] = max(tree[i], x);
		if(from != to) {
			lazy[l(i)] = max(lazy[l(i)], x);
			lazy[r(i)] = max(lazy[r(i)], x);
		}
		return;
	}
	int mid = (from + to) / 2;
	update(l(i), from, mid, ul, ur, x);
	update(r(i), mid + 1, to, ul, ur, x);
}


void solve_up(int x, int y) {
	debug("up\n");
	if(seen_x[x]) { puts("0"); return; }
	seen_x[x] = true;
	tree = treex; lazy = lazyx;
	int gy = query(1, 0, mx, x);
	debug("(x, y) = (%d, %d)... gy = %d\n", x, y, gy);
	debug("converted\n(x, y) = (%d, %d)... gy = %d\n", inv_mapx[x], inv_mapy[y], inv_mapy[gy]);
	printf("%d\n", inv_mapy[y] - inv_mapy[gy]);
	tree = treey; lazy = lazyy;
	debug("setting (%d -> %d) to %d\n", gy, y, x);
	update(1, 0, my, gy, y, x);
}

void solve_left(int x, int y) {
	debug("left\n");
	if(seen_x[x]) { puts("0"); return; }
	seen_x[x] = true;
	tree = treey; lazy = lazyy;
	int gx = query(1, 0, my, y);
	debug("(x, y) = (%d, %d)... gx = %d\n", x, y, gx);
	debug("converted\n(x, y) = (%d, %d)... gx = %d\n", inv_mapx[x], inv_mapy[y], inv_mapx[gx]);
	printf("%d\n", inv_mapx[x] - inv_mapx[gx]);
	tree = treex; lazy = lazyx;
	debug("setting (%d -> %d) to %d\n", gx, x, y);
	update(1, 0, mx, gx, x, y);	
}

void pre_fix() {
	int i, x, y; char c;
	map<int, int> sx, sy;
	sx[0] = 0; sx[n + 1] = 0;
	sy[0] = 0; sy[n + 1] = 0;
	for(i = 0; i < q; i++) {
		scanf("%d %d %c", &x, &y, &c);
		sx[x] = 0; sy[y] = 0;
		ops[i].set(x, y, c);
	}
	i = 0;
	for(auto el : sx) {
		inv_mapx[i] = el.first;
		sx[el.first] = i++;
	}
	i = 0;
	for(auto el : sy) {
		inv_mapy[i] = el.first;
		sy[el.first] = i++;
	}
	for(i = 0; i < q; i++) {
		ops[i].x = sx[ops[i].x];
		ops[i].y = sy[ops[i].y];
		mx = max(ops[i].x, mx);
		my = max(ops[i].y, my);
	}
}

int main() {
	int i, j, x, y;
	scanf("%d %d", &n, &q);
	pre_fix();
	for(i = 0; i < q; i++)
		if(ops[i].op == 'U')
			solve_up(ops[i].x, ops[i].y);
		else
			solve_left(ops[i].x, ops[i].y);
	return 0;
}