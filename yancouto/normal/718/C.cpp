#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int S = 2;

inline void mult(ll a[S][S], ll b[S][S], ll c[S][S]) {
	for(int i = 0; i < S; i++)
		for(int j = 0; j < S; j++) {
			c[i][j] = 0;
			for(int k = 0; k < S; k++)
				c[i][j] = mod(c[i][j] + a[i][k] * b[k][j]);
		}
}

inline void cp(ll a[S][S], ll b[S][S]) {
	for(int i = 0; i < S; i++)
		for(int j = 0; j < S; j++)
			b[i][j] = a[i][j];
}

ll a[S][S], b[S][S], c[S][S], aux[S][S];

inline void fexp(ll a[S][S], ll p, ll c[S][S]) {
	for(int i = 0; i < S; i++)
		for(int j = 0; j < S; j++)
			c[i][j] = (i == j);
	for(; p; p >>= 1) {
		if(p & 1) { mult(c, a, aux); cp(aux, c); }
		mult(a, a, aux); cp(aux, a);
	}
}

const int N = 112345;

ll tr[4 * N][S];
ll lazy[4 * N][S][S];

void build(int i, int l, int r) {
	lazy[i][0][0] = lazy[i][1][1] = 1;
	if(l == r) return (void)(tr[i][0] = 1);
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	tr[i][0] = mod(tr[2 * i][0] + tr[2 * i + 1][0]);
	tr[i][1] = mod(tr[2 * i][1] + tr[2 * i + 1][1]);
}

void unlaze(int i, int l, int r) {
	ll na = mod(tr[i][0] * lazy[i][0][0] + tr[i][1] * lazy[i][0][1]);
	ll nb = mod(tr[i][0] * lazy[i][1][0] + tr[i][1] * lazy[i][1][1]);
	tr[i][0] = na;
	tr[i][1] = nb;
	if(l != r) {
		mult(lazy[i], lazy[2 * i], aux); cp(aux, lazy[2 * i]);
		mult(lazy[i], lazy[2 * i + 1], aux); cp(aux, lazy[2 * i + 1]);
	}
	lazy[i][0][0] = lazy[i][1][1] = 1; lazy[i][0][1] = lazy[i][1][0] = 0;
}

ll query(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return 0;
	if(l >= ql && r <= qr) return tr[i][0];
	int m = (l + r) / 2;
	return mod(query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr));
}

void upd(int i, int l, int r, int ql, int qr, ll x[S][S]) {
	unlaze(i, l, r);
	if(r < ql || l > qr) return;
	if(l >= ql && r <= qr) {
		for(int i2 = 0; i2 < S; i2++)
			for(int j2 = 0; j2 < S; j2++)
				lazy[i][i2][j2] = x[i2][j2];
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(2 * i, l, m, ql, qr, x);
	upd(2 * i + 1, m + 1, r, ql, qr, x);
	tr[i][0] = mod(tr[2 * i][0] + tr[2 * i + 1][0]);
	tr[i][1] = mod(tr[2 * i][1] + tr[2 * i + 1][1]);
}


void all(int i, int l, int r) {
	unlaze(i, l, r);
	if(l == r) { printf("%d ", (int) tr[i][0]); return; }
	int m = (l + r) / 2;
	all(2 * i, l, m);
	all(2 * i + 1, m + 1, r);
}

void proc(ll x) {
	a[0][0] = a[0][1] = a[1][0] = 1; a[1][1] = 0;
	fexp(a, x, b); cp(b, a);
}

int main() {
	int i, j, n, m, x, l, r, op;
	scanf("%d %d", &n, &m);
	build(1, 0, n - 1);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		proc(x - 1);
		if(x > 1) upd(1, 0, n - 1, i, i, a);
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &op, &l, &r); l--; r--;
		if(op == 1) {
			scanf("%d", &x);
			proc(x);
			upd(1, 0, n - 1, l, r, a);
		} else {
			printf("%d\n", (int) query(1, 0, n - 1, l, r));
		}
	}
}