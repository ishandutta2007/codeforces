#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss
#define matr vector<vector<int>>

const int N = 1e6;
const int C = -1;
const int BASE = 1e9 + 7;

struct Tree {
	int f0, f1;
	int ff0, ff1;
	int l, r;
	Tree() {}
};

Tree tr[N];
int p[N];
matr A, E;
int n, m;

matr sum(matr a, matr b) {
	matr c(2, vector<int>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c[i][j] = a[i][j] + b[i][j];
			if (c[i][j] >= BASE) c[i][j] -= BASE;
		}
	}
	return c;
}

inline matr mul(matr a, matr b) {
	if (a == E) return b;
	if (b == E) return a;
	matr c(2, vector<int>(2));
	c[0][0] = (a[0][0] * 1LL * b[0][0] + a[0][1] * 1LL * b[1][0]) % BASE;
	c[0][1] = (a[0][0] * 1LL * b[0][1] + a[0][1] * 1LL * b[1][1]) % BASE;
	c[1][0] = (a[1][0] * 1LL * b[0][0] + a[1][1] * 1LL * b[1][0]) % BASE;
	c[1][1] = (a[1][0] * 1LL * b[0][1] + a[1][1] * 1LL * b[1][1]) % BASE;
	return c;
}

pair<int, int> pw(int n) {
	int r00 = 1, r01 = 0, r10 = 0, r11 = 1;
	int a00 = 0, a01 = 1, a10 = 1, a11 = 1;
	while (n) {
		if (n & 1) {
			int nr00 = (r00 * 1LL * a00 + r01 * 1LL * a10) % BASE;
			int nr01 = (r00 * 1LL * a01 + r01 * 1LL * a11) % BASE;
			int nr10 = (r10 * 1LL * a00 + r11 * 1LL * a10) % BASE;
			int nr11 = (r10 * 1LL * a01 + r11 * 1LL * a11) % BASE;
			r00 = nr00; r01 = nr01; r10 = nr10; r11 = nr11;
		}
		int na00 = (a00 * 1LL * a00 + a01 * 1LL * a10) % BASE;
		int na01 = (a00 * 1LL * a01 + a01 * 1LL * a11) % BASE;
		int na10 = (a10 * 1LL * a00 + a11 * 1LL * a10) % BASE;
		int na11 = (a10 * 1LL * a01 + a11 * 1LL * a11) % BASE;
		a00 = na00; a01 = na01; a10 = na10; a11 = na11;
		n /= 2;
	}
	return make_pair((r00 + r01) % BASE, (r10 + r11) % BASE);
}

void build(int x, int l, int r) {
	int mid = (l + r) / 2;
	tr[x].ff0 = 1;
	tr[x].ff1 = 0;
	tr[x].l = l;
	tr[x].r = r;
	if (l < r) {
		build(x + x + 1, l, mid);
		build(x + x + 2, mid + 1, r);
		tr[x].f0 = (tr[x + x + 1].f0 + tr[x + x + 2].f0) % BASE;
		tr[x].f1 = (tr[x + x + 1].f1 + tr[x + x + 2].f1) % BASE;
	} else {
		pair<int, int> tmp = pw(p[l]);
		tr[x].f0 = tmp.first;
		tr[x].f1 = tmp.second;
	}
}

void apply(int x, int ff0, int ff1) {
	int nf0 = (tr[x].f0 * 1LL * ff0 + tr[x].f1 * 1LL * ff1) % BASE;
	int nf1 = (tr[x].f0 * 1LL * ff1 + tr[x].f1 * 1LL * (ff0 + ff1)) % BASE;
	tr[x].f0 = nf0;
	tr[x].f1 = nf1;
	
	int nff0 = (tr[x].ff0 * 1LL * ff0 + tr[x].ff1 * 1LL * ff1) % BASE;
	int nff1 = (tr[x].ff0 * 1LL * ff1 + tr[x].ff1 * 1LL * (ff0 + ff1)) % BASE;
	tr[x].ff0 = nff0;
	tr[x].ff1 = nff1;
}

void push(int x) {
	if ((tr[x].ff0 == 1) && (tr[x].ff1 == 0)) return;
	apply(x + x + 1, tr[x].ff0, tr[x].ff1);
	apply(x + x + 2, tr[x].ff0, tr[x].ff1);
	tr[x].ff0 = 1;
	tr[x].ff1 = 0;
}

void upd(int x) {
	tr[x].f0 = (tr[x + x + 1].f0 + tr[x + x + 2].f0) % BASE;
	tr[x].f1 = (tr[x + x + 1].f1 + tr[x + x + 2].f1) % BASE;
}

int getsum(int x, int l, int r) {
	if ((tr[x].l == l) && (tr[x].r == r)) return tr[x].f0;
	push(x);
	int res = 0;
	if (l <= tr[x + x + 1].r) {
		res += getsum(x + x + 1, l, min(r, tr[x + x + 1].r));
		if (res >= BASE) res -= BASE;
	}
	if (r >= tr[x + x + 2].l) {
		res += getsum(x + x + 2, max(l, tr[x + x + 2].l), r);
		if (res >= BASE) res -= BASE;
	}
	return res;
}

void mul(int x, int l, int r, int ff0, int ff1) {
	if ((tr[x].l == l) && (tr[x].r == r)) {
		apply(x, ff0, ff1);
		return;
	}
	push(x);
	if (l <= tr[x + x + 1].r) mul(x + x + 1, l, min(r, tr[x + x + 1].r), ff0, ff1);
	if (r >= tr[x + x + 2].l) mul(x + x + 2, max(l, tr[x + x + 2].l), r, ff0, ff1);
	upd(x);
}

int main() {
	// freopen("input.txt", "r", stdin);
	A.assign(2, vector<int>(2, 1));
	A[0][0] = 0;
	E.assign(2, vector<int>(2));
	E[0][0] = E[1][1] = 1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		--p[i];
	}
	build(0, 0, n - 1);
	// matr tmpA = pw(A, 1e9);
	for (int i = 0; i < m; i++) {
		int tp;
		scanf("%d", &tp);
		if (tp == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", getsum(0, l - 1, r - 1));
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l; --r; --x;
			pair<int, int> add = pw(x);
			// matr add = tmpA;
			int f0 = add.first;
			int f1 = add.second;
			int pf0 = (f1 - f0 + BASE) % BASE;
			mul(0, l, r, pf0, f0);
		}
	}
	cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}