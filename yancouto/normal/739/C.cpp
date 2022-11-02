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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

const int N = 312345, M = 4 * N;

int a[N]; ll bit[N];
ll bl[N], br[N];
void add(int i, int x, ll b[]=bit) { for(i += 2; i < N; i += (i & -i)) b[i] += x; }
ll get(int i, ll b[]=bit) {
	ll x = 0;
	for(i += 2; i; i -= (i & -i))
		x += b[i];
	return x;
}

ll f[M], lzf[M];
void unlzf(int i, int l, int r) {
	f[i] += lzf[i];
	if(l != r) lzf[2 * i] += lzf[i], lzf[2 * i + 1] += lzf[i];
	lzf[i] = 0;
}

void addf(int i, int l, int r, int ql, int qr, int x) {
	if(i == 1) debug("add [%d, %d] += %d\n", ql, qr, x);
	unlzf(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lzf[i] = x;
		unlzf(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	addf(2 * i, l, m, ql, qr, x);
	addf(2 * i + 1, m + 1, r, ql, qr, x);
	f[i] = max(f[2 * i], f[2 * i + 1]);
}

ll queryf(int i, int l, int r, int ql, int qr) {
	unlzf(i, l, r);
	if(l > qr || r < ql) return INT_MIN;
	if(l >= ql && r <= qr) return f[i];
	int m = (l + r) / 2;
	return max(queryf(2 * i, l, m, ql, qr), queryf(2 * i + 1, m + 1, r, ql, qr));
}

#define set set_
int sl[M], sr[M];

void build(int i, int l, int r) {
	if(l == r) sl[i] = sr[i] = l;
	else {
		sl[i] = sr[i] = -1;
		int m = (l + r) / 2;
		build(2 * i, l, m);
		build(2 * i + 1, m + 1, r);
	}
}

void unlaze(int t[], int i, int l, int r) {
	if(t[i] == -1 || l == r) return;
	t[2 * i] = t[2 * i + 1] = t[i];
	t[i] = -1;
}

int get(int t[], int i, int l, int r, int p) {
	unlaze(t, i, l, r);
	if(l == r) return t[i];
	int m = (l + r) / 2;
	if(p <= m) return get(t, 2 * i, l, m, p);
	else return get(t, 2 * i + 1, m + 1, r, p);
}

void set(int t[], int i, int l, int r, int ql, int qr, int x) {
	unlaze(t, i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		t[i] = x;
		unlaze(t, i, l, r);
		return;
	}
	int m = (l + r) / 2;
	set(t, 2 * i, l, m, ql, qr, x);
	set(t, 2 * i + 1, m + 1, r, ql, qr, x);
}

int vall[N], valr[N];

void query(int l, int r, int x) {
	debug("===== QUERY [%d, %d] += %d\n", l, r, x);
	// r right
	if(r < n - 1 && get(r) <= get(r + 1) && get(r) + x > get(r + 1)) {
		debug("r right\n");
		int v = get(r + 1, br);
		int ql = vall[r];
		addf(1, 0, n - 1, ql, r, v + 1);
		add(ql, v + 1, br);
		add(r + 1, -(v + 1), br);
		int sink = get(sr, 1, 0, n - 1, r + 1);
		set(sr, 1, 0, n - 1, ql, r, sink);
		vall[sink] = ql;
	}
	// r left
	if(l && get(l) < get(l - 1) && get(l) + x >= get(l - 1)) {
		debug("r left\n");
		int v = get(l, br);
		int sink = get(sr, 1, 0, n - 1, l);
		int ql = vall[sink];
		vall[sink] = l;
		addf(1, 0, n - 1, ql, l - 1, -(v + 1));
		add(ql, -(v + 1), br);
		add(l, v + 1, br);
		set(sr, 1, 0, n - 1, ql, l - 1, l - 1);
		vall[l - 1] = ql;
	}
	// l left
	if(l && get(l) <= get(l - 1) && get(l) + x > get(l - 1)) {
		debug("l left\n");
		int v = get(l - 1, bl);
		int qr = valr[l];
		addf(1, 0, n - 1, l, qr, v + 1);
		add(l, v + 1, bl);
		add(qr + 1, -(v + 1), bl);
		int sink = get(sl, 1, 0, n - 1, l - 1);
		set(sl, 1, 0, n - 1, l, qr, sink);
		valr[sink] = qr;
	}
	// l right
	if(r < n - 1 && get(r + 1) > get(r) && get(r + 1) <= get(r) + x) {
		debug("l right\n");
		int v = get(r, bl);
		int sink = get(sl, 1, 0, n - 1, r);
		int qr = valr[sink];
		valr[sink] = r;
		addf(1, 0, n - 1, r + 1, qr, -(v + 1));
		add(r + 1, -(v + 1), bl);
		add(qr + 1, v + 1, bl);
		set(sl, 1, 0, n - 1, r + 1, qr, r + 1);
		valr[r + 1] = qr;
	}

	add(l, x);
	add(r + 1, -x);
	debug("------- AFTER %lld\n", queryf(1, 0, n - 1, 0, n - 1) + 1ll);
}

int main() {
	int i, j, m, l, r, x;
	rd(n);
	build(1, 0, n - 1);
	for(i = 0; i < n; i++) vall[i] = valr[i] = i;
	for(i = 0; i < n; i++) rd(a[i]), query(i, i, a[i]);
	rd(m);
	for(i = 0; i < m; i++) {
		rd(l); rd(r); rd(x); l--; r--;
		query(l, r, x);
		printf("%lld\n", queryf(1, 0, n - 1, 0, n - 1) + 1ll);
	}
}