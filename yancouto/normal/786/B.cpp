#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
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

struct piii {
	int l, r; ll w;
};

const int N = 112345;

const int M = 212345 * 8;

ll tr[M], lz[M];

void build(int i, int l, int r) {
	tr[i] = LLONG_MAX - 1;
	lz[i] = LLONG_MAX - 1;
	if(l == r) return;
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

void unlaze(int i, int l, int r) {
	if(tr[i] == LLONG_MAX) return;
	tr[i] = min(tr[i], lz[i]);
	lz[2 * i] = min(lz[2 * i], lz[i]);
	lz[2 * i + 1] = min(lz[2 * i + 1], lz[i]);
	lz[i] = LLONG_MAX - 1;
}

void setmn(int i, int l, int r, int ql, int qr, ll v, bool force) {
	unlaze(i, l, r);
	if(tr[i] == LLONG_MAX) return;
	//debug("(%d, %d, %d, %d, %d, %lld, %d) = %lld\n", i, l, r, ql, qr, v, force, tr[i]);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr && force) {
		return (void) (tr[i] = v);
	}
	if(l >= ql && r <= qr) {
		lz[i] = v;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	setmn(2 * i, l, m, ql, qr, v, force);
	setmn(2 * i + 1, m + 1, r, ql, qr, v, force);
	tr[i] = min(tr[2 * i], tr[2 * i + 1]);
}

pii get(int i, int l, int r) {
	unlaze(i, l, r);
	if(l == r) return pii(l, tr[i]);
	int m = (l + r) / 2;
	unlaze(2 * i, l, m); unlaze(2 * i + 1, m + 1, r);
	if(tr[2 * i] <= tr[2 * i + 1])
		return get(2 * i, l, m);
	else
		return get(2 * i + 1, m + 1, r);
}

vector<piii> adj[N];

set<int> ans;

int L[N], R[N], v[N]; ll w[N];
set<int> t2[M];
void add(int i, int l, int r, int ql, int qr, int id, bool rm) {
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		//printf("%d on [%d,%d]\n", id, l, r);
		if(!rm) t2[i].insert(id);
		else t2[i].erase(id);
		return;
	}
	int m = (l + r) / 2;
	add(2 * i, l, m, ql, qr, id, rm);
	add(2 * i + 1, m + 1, r, ql, qr, id, rm);
}

void query(int i, int l, int r, int p) {
	for(int x : t2[i])
		ans.insert(x);
	if(l == r) return;
	int m = (l + r) / 2;
	if(p <= m) query(2 * i, l, m, p);
	else query(2 * i + 1, m + 1, r, p);
}

ll d[N];

int main() {
	int i, j;
	int n, q, s, u, v, l, r, t; ll w;
	rd(n); rd(q); rd(s);
	for(i = 0; i < q; i++) {
		rd(t);
		if(t == 1) {
			rd(u); rd(v); rd(w);
			adj[u].pb(piii{v, v, w});
		} else {
			rd(::v[i]); rd(L[i]); rd(R[i]); rd(::w[i]);
			if(t == 2)
				adj[::v[i]].pb(piii{L[i], R[i], ::w[i]});
			else add(1, 1, n, L[i], R[i], i, false);
		}
	}

	build(1, 1, n);
	setmn(1, 1, n, s, s, 0, false);
	memset(d, -1, sizeof d);
	while(true) {
		pii p = get(1, 1, n);
		if(p.snd >= LLONG_MAX - 1) break;
		d[p.fst] = p.snd;
		int x = p.fst;
		//debug("x %d | %lld\n", x, d[x]);
		setmn(1, 1, n, x, x, LLONG_MAX, true);
		for(piii e : adj[x])
			setmn(1, 1, n, e.l, e.r, d[x] + e.w, false);
		ans.clear();
		query(1, 1, n, x);
		for(int id : ans) {
			add(1, 1, n, L[id], R[id], id, true);
			//printf("%d->%d : %lld + %lld\n", x, ::v[id], d[x], ::w[id]);
			setmn(1, 1, n, ::v[id], ::v[id], d[x] + ::w[id], false);
		}
	}
	for(i = 1; i <= n; i++)
		printf("%lld%c", d[i], " \n"[i == n]);
}