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

const int N = 512345;
const int M = 4 * N;

struct no {
	int rat;
	int mn[2];
	int& mn_up() { return mn[0]; }
	int& mn_dw() { return mn[1]; }
} tr[M];

struct lazy {
	int rat;
} lz[M];

void unlaze(int i, int l, int r) {
	tr[i].rat += lz[i].rat;
	tr[i].mn_up() -= lz[i].rat;
	tr[i].mn_dw() += lz[i].rat;
	if(l != r)
		for(int j = 2 * i; j <= 2 * i + 1; j++)
			lz[j].rat += lz[i].rat;
	lz[i].rat = 0;
}

inline no join(no a, no b) {
	return {min(a.rat, b.rat), min(a.mn_up(), b.mn_up()), min(a.mn_dw(), b.mn_dw())};
}

inline no def() { return {modn, modn, modn}; }

void build(int i, int l, int r) {
	tr[i] = {0, modn, modn};
	if(l == r) return;
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

void set_(int i, int l, int r, int p, no x) {
	unlaze(i, l, r);
	if(l == r) return (void) (tr[i] = x);
	int m = (l + r) / 2;
	if(p <= m) set_(2 * i, l, m, p, x);
	else set_(2 * i + 1, m + 1, r, p, x);
	tr[i] = join(tr[2 * i], tr[2 * i + 1]);
}

void upd(int i, int l, int r, int ql, int qr, int add) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lz[i].rat = add;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(2 * i, l, m, ql, qr, add);
	upd(2 * i + 1, m + 1, r, ql, qr, add);
	tr[i] = join(tr[2 * i], tr[2 * i + 1]);
}

no get(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return def();
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return join(get(2 * i, l, m, ql, qr), get(2 * i + 1, m + 1, r, ql, qr));
}

int que(int i, int l, int r, int ql, bool dw) {
	unlaze(i, l, r);
	if(tr[i].mn[dw] > 1 || r < ql) return INT_MAX;
	if(l == r) return l >= ql? l : INT_MAX;
	int m = (l + r) / 2;
	unlaze(2 * i, l, m);
	unlaze(2 * i + 1, m + 1, r);
	int g = que(2 * i, l, m, ql, dw);
	if(g != INT_MAX) return g;
	return que(2 * i + 1, m + 1, r, ql, dw);
}

set<int> eq;

inline int sign(int x) { return (x > 0) - (x < 0); }

void add(int i, int val) {
	//printf("[[[%d]]]\n", i);
	int rat = get(1, 0, n, i, i).rat;
	if(val == rat) {
		eq.insert(i);
		//printf("%d == %d\n", val, rat);
		printf("%d\n", get(1, 0, n, n, n).rat);
		return;
	}
	auto it = eq.lower_bound(i);
	int j = it == eq.end()? INT_MAX : *it;
	int oj = j;
	j = min(j, que(1, 0, n, i, val < rat));
	//printf("at %d next %d will %d > %d\n", i, j, val, rat);
	if(j < n && j == oj) {
		eq.erase(it);
		no x = get(1, 0, n, j, j);
		x.mn[0] = x.mn[1] = 1e9;
		x.mn[val > rat] = 0;
		set_(1, 0, n, j, x);
	} else if(j < n) {
		//printf("=-==\n");
		no x = get(1, 0, n, j, j);
		x.mn[0] = x.mn[1] = 1e9;
		set_(1, 0, n, j, x);
		eq.insert(j);
	}
	//printf("(%d, %d) += %d\n", i, min(n, j), sign(val - rat));
	upd(1, 0, n, i, min(n, j), sign(val - rat));
	no y = get(1, 0, n, i, i);
	y.mn[val < rat] = abs(val - rat);
	//printf("y.mn[%d] = %d\n", val < rat, abs(val - rat));
	set_(1, 0, n, i, y);
	printf("%d\n", get(1, 0, n, n, n).rat);
}

int a[N], p[N], q[N];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) {
		rd(a[i]); p[i] = q[i] = i;
		if(a[i] > 1000000) a[i] = 1000000;
		if(a[i] < -1000000) a[i] = -1000000;
	}
	sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });
	for(i = 0; i < n; i++)
		q[p[i]] = i;
	build(1, 0, n);
	for(i = 0; i < n; i++)
		add(q[i], a[i]);
}