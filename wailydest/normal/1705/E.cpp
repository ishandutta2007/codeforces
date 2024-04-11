#include <cstdio>

const int N = 200100;
int n, q, set[N * 2], a[N];
bool t[N * 2][2];

void push(int v, int tl, int tr) {
	if (set[v] != -1) {
		t[v][set[v]] = 1;
		t[v][!set[v]] = 0;
		if (tl + 1 < tr) set[v + 1] = set[v + (tr - tl & ~1)] = set[v];
		set[v] = -1;
	}
}

int next(int i, int x, int v = 0, int tl = 0, int tr = N) {
	push(v, tl, tr);
	if (!t[v][x] || tr <= i) return -1;
	if (tr - tl == 1) return tl;
	int m = tl + tr >> 1, k = next(i, x, v + 1, tl, m);
	if (k == -1) k = next(i, x, v + (tr - tl & ~1), m, tr);
	return k;
}

void upd(int l, int r, int x, int v = 0, int tl = 0, int tr = N) {
	push(v, tl, tr);
	if (tl >= r || tr <= l) return;
	if (tl >= l && tr <= r) {
		set[v] = x;
		push(v, tl, tr);
	} else {
		int m = tl + tr >> 1;
		upd(l, r, x, v + 1, tl, m);
		upd(l, r, x, v + (tr - tl & ~1), m, tr);
		t[v][0] = t[v + 1][0] || t[v + (tr - tl & ~1)][0];
		t[v][1] = t[v + 1][1] || t[v + (tr - tl & ~1)][1];
	}
}

int calc(int v = 0, int tl = 0, int tr = N) {
	push(v, tl, tr);
	if (tr - tl == 1) return tl;
	int m = tl + tr >> 1;
	push(v + (tr - tl & ~1), m, tr);
	if (t[v + (tr - tl & ~1)][1]) return calc(v + (tr - tl & ~1), m, tr);
	return calc(v + 1, tl, m);
}

void add(int p) {
	int k = next(p, 0);
	if (p < k) upd(p, k, 0);
	upd(k, k + 1, 1);
}

void sub(int p) {
	int k = next(p, 1);
	if (p < k) upd(p, k, 1);
	upd(k, k + 1, 0);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < N * 2; ++i) {
		set[i] = -1;
		t[i][0] = 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		add(a[i]);
	}
	while (q--) {
		int k, l;
		scanf("%d%d", &k, &l);
		--k;
		sub(a[k]);
		a[k] = l;
		add(a[k]);
		printf("%d\n", calc());
	}
	return 0;
}