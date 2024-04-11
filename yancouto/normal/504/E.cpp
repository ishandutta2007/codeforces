#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000009;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const ll b = 263;
const int N = 312345;

int lc[N][20], nv[N];
vector<int> adj[N];
ll hd[N], hu[N], pot[N], inv[N];
char c[N];

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}
int g[N];
int mh[N], ph[N];
deque<int> pt[N];

inline int anc(int u, int d) {
	if(d == 0) return u;
	u = lc[u][g[d]];
	d -= (1 << g[d]);
	int p = nv[u] - nv[ph[u]] + (pt[ph[u]].size() / 2);
	return pt[ph[u]][p - d];
}

inline int anc2(int u, int d) {
	while(d) {
		u = lc[u][g[d]];
		d -= (1 << g[d]);
	}
	return u;
}

int lca(int u, int v) {
	if(nv[u] > nv[v]) swap(u, v);
	v = anc(v, nv[v] - nv[u]);
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(lc[v][i] != lc[u][i])
			u = lc[u][i], v = lc[v][i];
	return lc[u][0];
}


void dfs2(int u, int p) {
	ph[u] = p;
	bool any = false;
	pt[p].pb(u);
	for(int v : adj[u])
		if(!any && mh[v] + 1 == mh[u]) dfs2(v, p), any = true;
		else dfs2(v, v);
	if(adj[u].empty()) {
		int sz = pt[p].size();
		while(sz--) pt[p].push_front(lc[pt[p][0]][0]);
	}
}

int dfs(int u, int p, ll hs, ll hr, int nv) {
	if(u) adj[u].erase(search_n(adj[u].begin(), adj[u].end(), 1, p));
	::nv[u] = nv;
	lc[u][0] = p;
	for(int i = 1; i < 20; i++)
		lc[u][i] = lc[lc[u][i - 1]][i - 1];
	hu[u] = hs = mod(hs * b + c[u]);
	hd[u] = hr = mod(hr + ll(c[u]) * pot[nv]);
	mh[u] = 0;
	for(int v : adj[u])
		mh[u] = max(mh[u], dfs(v, u, hs, hr, nv + 1) + 1);
	return mh[u];
}

inline ll get_up(int a, int b) {
	ll h = mod(hd[a] - hd[b] + modn);
	return mod(h * inv[nv[b]+1]);
}

inline ll get_down(int a, int b) {
	return mod(hu[a] - mod(hu[b] * pot[nv[a] - nv[b]]) + modn);
}

ll get_hash(int a, int b, int ab, int m) {
	int pa = nv[a] - nv[ab] + 1, pb = nv[b] - nv[ab];
	ll f, s; int sz;
	if(m <= pa) {
		f = get_up(a, anc(a, m)); s = 0;
		sz = 0;
	} else {
		f = get_up(a, lc[ab][0]);
		sz = m - pa;
		s = get_down(anc(b, pa + pb - m), ab);
	}
	return mod(f * pot[sz] + s);
}

#define gc getchar
inline int get() {
	char c;
	while(isspace(c = gc()));
	int v = c - '0';
	while(isdigit(c = gc())) v = (v << 3) + (v << 1) + (c - '0');
	return v;
}

#define pc putchar

inline void out(int x) {
	int sz = 0, v = 0;
	while(x) v = (v << 3) + (v << 1) + (x % 10), x /= 10, sz++;
	while(sz--) pc('0' + (v % 10)), v /= 10;
	putchar('\n');
}

int main() {
	srand(time(NULL));
	int i, j, n, a, b, c, d, q;
	n = get();
	scanf(" %s", ::c + 1);
	for(i = 2; i <= n; i++)
		g[i] = g[i >> 1] + 1;
	int o = (rand() % n) + 1;
	adj[0].pb(o); adj[o].pb(0);
	for(i = 0; i < n - 1; i++) {
		a = get(); b = get();
		adj[a].pb(b);
		adj[b].pb(a);
	}
	pot[0] = 1;
	for(i = 1; i < N; i++) pot[i] = mod(pot[i - 1] * ::b);
	inv[N - 1] = fexp(pot[N - 1], modn - 2);
	for(i = N - 2; i >= 0; i--) inv[i] = mod(inv[i + 1] * ::b);
	dfs(0, 0, 0, 0, 0);
	dfs2(0, 0);
	q = get();
	for(i = 0; i < q; i++) {
		a = get(); b = get(); c = get(); d = get();
		if(::c[a] != ::c[c]) { puts("0"); continue; }
		int ab = lca(a, b), cd = lca(c, d);
		int l = 1, r = min(nv[a] + nv[b] - 2*nv[ab] + 1, nv[c] + nv[d] - 2*nv[cd] + 1);
		while(l < r) {
			int m = (l + r + 1) / 2;
			ll hab = get_hash(a, b, ab, m), hcd = get_hash(c, d, cd, m);
			if(hab == hcd) l = m;
			else r = m - 1;
		}
		//out(l);
		printf("%d\n", l);
	}
}