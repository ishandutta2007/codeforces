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
#	define debug(args...) ((void) 0)
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

const int N = 312345;
typedef int num;

int en = 1;
int p[N], sz[N];
int C[N][2]; // {left, right} children
int pp[N]; bool lzswp[N];

// atualize os valores associados aos nos que podem ser calculados a partir dos filhos
inline void calc(int u) {
	sz[u] = sz[C[u][0]] + 1 + sz[C[u][1]];
}

inline void unlaze(int u) {
	if(!u) return;
	if(lzswp[u]) {
		swap(C[u][0], C[u][1]);
		if(C[u][0]) lzswp[C[u][0]] ^= 1;
		if(C[u][1]) lzswp[C[u][1]] ^= 1;
		lzswp[u] = 0;
	}
}


// Puxa o filho dir de u para ficar em sua posicao e o retorna
int rotate(int u, int dir) {
	int v = C[u][dir];
	swap(pp[v], pp[u]);
	C[u][dir] = C[v][!dir];
	if(C[u][dir]) p[C[u][dir]] = u;
	C[v][!dir] = u;
	p[v] = p[u];
	if(p[v]) C[p[v]][C[p[v]][1] == u] = v;
	p[u] = v;
	calc(u);
	calc(v);
	return v;
}

void unlz_back(int u) {
	if(!u) return;
	unlz_back(p[u]);
	unlaze(u);
}

// Traz o no u a raiz
void splay(int u) {
	unlz_back(u);
	//printf("splay(%d) %d\n", u, sz[u]);
	while(p[u]) {
		int v = p[u], w = p[p[u]];
		int du = (C[v][1] == u);
		if(!w) {
			rotate(v, du);
			assert(!p[u]);
		} else {
			int dv = (C[w][1] == v);
			if(du == dv) {
				rotate(w, dv);
				assert(C[v][du] == u);
				rotate(v, du);
			} else {
				rotate(v, du);
				assert(C[w][dv] == u);
				rotate(w, dv);
			}
		}
	}
}

// retorna o s-esimo no (0-indexed)
int find_sz(int u, int s) {
	unlaze(u);
	while(sz[C[u][0]] != s) {
		if(sz[C[u][0]] < s) {
			s -= sz[C[u][0]] + 1;
			u = C[u][1];
		} else u = C[u][0];
		unlaze(u);
	}
	splay(u);
	return u;
}

// chame isso 1 vez no inicio
void init() {
	en = 1;
}

// Cria um novo no
int new_node() {
	int i = en++;
	assert(i < N);
	pp[i] = C[i][0] = C[i][1] = p[i] = 0;
	lzswp[i] = 0;
	sz[i] = 1;
	return i;
}

int access(int u) {
	if(!u) return u;
	splay(u);
	if(int v = C[u][1]) {
		p[v] = 0;
		pp[v] = u;
		C[u][1] = 0;
	}
	calc(u);
	while(pp[u]) {
		int w = pp[u];
		splay(w);
		if(int v = C[w][1]) {
			p[v] = 0;
			pp[v] = w;
		}
		C[w][1] = u;
		p[u] = w;
		pp[u] = 0;
		calc(w);
		splay(u);
	}
	return u;
}

// retorna a raiz da arvore de u
int find_root(int u) {
	access(u);
	while(C[u][0]) { unlaze(u = C[u][0]); }
	access(u);
	return u;
}

// pai de u. pode mudar por causa de rootify
int get_parent(int u) {
	access(u);
	if(!C[u][0]) return pp[u];
	unlaze(u = C[u][0]);
	while(C[u][1]) unlaze(u = C[u][1]);
	access(u);
	return u;
}

// adiciona aresta de u para v
// v deve ser raiz de sua arvore
void link(int u, int v) {
	if(find_root(u) == find_root(v)) return;
	access(u); access(v);
	assert(C[v][0] == 0 && pp[v] == 0 && sz[v] == 1); // v deve ser raiz
	C[u][1] = v;
	p[v] = u;
	calc(u);
}

// remove o link de u para seu pai
void cut(int u) {
	access(u);
	assert(C[u][0]); // deve ter pai
	p[C[u][0]] = 0;
	C[u][0] = 0;
	calc(u);
}

// faz u ser a raiz de sua arvore.
// XXX cuidado ao misturar rootify e cut, use get_parent
void rootify(int u) {
	access(u);
	lzswp[u] = 1;
	access(u);
}


int a[N], b[N];

int mx[N];

void add(ll bit[], int i, ll x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}

ll get(ll bit[], int i) {
	ll sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}

ll get(ll bit[], int i, int j) {
	return get(bit, j) - get(bit, i - 1);
}

ll bitc[N], bittot[N], bitpos[N];

int pi[N], pq[N];
int l[N], r[N];
ll ans[N];

vector<int> adjb[N], adjf[N];

bool ok_vx(int L, int u) {
	while(!adjb[u].empty()) {
		int v = adjb[u].back();
		if(v < L) {
			adjb[u].pop_back();
			continue;
		}
		if(find_root(v) == find_root(u)) return false;
		rootify(v);
		link(u, v);
		adjb[u].pop_back();
	}
	return true;
}

int main() {
	int i;
	int n, m;
	init();
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a[i]); rd(b[i]);
		adjb[max(a[i], b[i])].pb(min(a[i], b[i]));
		adjf[min(a[i], b[i])].pb(max(a[i], b[i]));
	}
	for(i = 1; i <= n; i++) {
		sort(adjb[i].begin(), adjb[i].end());
	}
	int r = 0;
	for(i = 1; i <= n; i++) {
		while(r + 1 <= n && ok_vx(i, r + 1)) {
			r++;
		}
		mx[i] = r;
		rootify(i);
		for(int v : adjf[i]) {
			if(v > r) continue;
			if(get_parent(v) == i) {
				cut(v);
			} else {
				cut(i);
			}
		}

		debug("mx[%d] = %d\n", i, mx[i]);
	}
	int q;
	rd(q);
	for(i = 0; i < q; i++) {
		rd(l[i]); rd(::r[i]);
		pq[i] = i;
	}
	for(i = 0; i < n; i++) pi[i] = i;
	sort(pi + 1, pi + n + 1, [](int i, int j) { return mx[i] < mx[j]; });
	sort(pq, pq + q, [](int i, int j) { return ::r[i] < ::r[j]; });
	for(i = 1; i <= n; i++) add(bitc, i, 1), add(bitpos, i, i);
	int ri = 1;
	for(int qi_ = 0; qi_ < q; qi_++) {
		int qi = pq[qi_];
		while(ri <= n && mx[pi[ri]] <= ::r[qi]) {
			int i = pi[ri++];
			debug("adding element %d\n", i);
			add(bitc, i, -1);
			add(bitpos, i, -i);
			add(bittot, i, mx[i] - i + 1);
		}
		ll L = l[qi], R = ::r[qi];
		debug("Answering query (%lld, %lld)\n", L, R);
		ll &a = ans[qi];
		a = get(bittot, L, R);
		a += ll(R + 1) * get(bitc, L, R) - get(bitpos, L, R);
	}
	for(i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
}