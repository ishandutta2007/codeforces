#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct node_t {
    node_t *p, *l, *r;
    int size, rev;
    int s, w;
    node_t() : p(0), l(0), r(0), size(1), rev(0), s(0), w(1) {}
};

int isrt(node_t* x) {
    return !(x->p) || (x->p->l != x && x->p->r != x);
}

int left(node_t* x) {
    return x->p->l == x;
}

void setchild(node_t* x, node_t* p, int l) {
    (l ? p->l : p->r) = x;
    if (x) x->p = p;
}

void push(node_t* x) {
    node_t* u = x->l;
    node_t* v = x->r;
    if (x->rev) {
        if (u) swap(u->l, u->r), u->rev ^= 1;
        if (v) swap(v->l, v->r), v->rev ^= 1;
        x->rev = 0;
    }
}

int size(node_t* x) {
    return x ? x->size : 0;
}

int sum(node_t* x) {
    return x ? x->s : 0;
}

void pull(node_t* x) {
    x->size = size(x->l) + 1 + size(x->r);
    x->s = sum(x->l) + x->w + sum(x->r);
}

void rotate(node_t* x) {
    node_t *p = x->p, *g = p->p;
    int l = left(x);
    setchild(l ? x->r : x->l, p, l);
    if (!isrt(p)) setchild(x, g, left(p));
    else x->p = g;
    setchild(p, x, !l);
    pull(p);
}

node_t* splay(node_t* x) {
    push(x);
    while (!isrt(x)) {
        node_t *p = x->p, *g = p->p;
        if (g) push(g);
        push(p), push(x);
        if (!isrt(p)) rotate(left(x) != left(p) ? x : p);
        rotate(x);
    }
    pull(x);
    return x;
}

node_t* access(node_t* x) {
    node_t* z = 0;
    for (node_t* y = x; y; y = y->p) {
        splay(y);
        y->w += sum(y->r);
        y->r = z;
        y->w -= sum(y->r);
        pull(z = y);
    }
    splay(x);
    return z;
}

void link(node_t* x, node_t* p) {
    access(x), access(p);
    x->p = p;
    p->w += sum(x);
}

void cut(node_t* x) {
    access(x);
    x->l->p = 0, x->l = 0;
    pull(x);
}

void makeroot(node_t* x) {
    access(x);
    x->rev ^= 1;
    swap(x->l, x->r);
}

node_t* findroot(node_t* x) {
    access(x);
    while (x->l) push(x), x = x->l;
    push(x);
    return splay(x);
}

node_t* lca(node_t* x, node_t* y) {
    if (findroot(x) != findroot(y)) return 0;
    access(x);
    return access(y);
}

int connect(node_t* x, node_t* y) {
    if (x == y) return 1;
    access(x), access(y);
    return x->p != 0;
}

int treequery(node_t* x) {
    access(x);
    return x->w;
}

const int maxn = 2e5 + 5;
int n, m;
vector<vi> a;
node_t pool[maxn];

void makeroot(int u) {
    makeroot(pool + u);
}

void link(int u, int v) {
    link(pool + u, pool + v);
}

void cut(int u) {
    cut(pool + u);
}

int findroot(int u) {
    return findroot(pool + u) - pool;
}

int lca(int u, int v) {
    node_t* a = lca(pool + u, pool + v);
    if (!a) return -1;
    return a - pool;
}

int connect(int u, int v) {
    return connect(pool + u, pool + v);
}

int treequery(int u) {
    return treequery(pool + u);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int inside(int u, int v) {
    if (!(0 <= u && u < n)) return 0;
    if (!(0 <= v && v < m)) return 0;
    return 1;
}

pi merge(pi a, pi b) {
    pi res = mp(min(a.fi, b.fi), 0);
    if (res.fi == a.fi) {
        res.se += a.se;
    }
    if (res.fi == b.fi) {
        res.se += b.se;
    }
    return res;
}

pi st[maxn << 2];
int lz[maxn << 2];
void build(int p, int L, int R) {
    if (L == R) {
        st[p] = mp(0, 1);
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
void push(int p, int L, int R) {
    if (lz[p]) {
        st[p].fi += lz[p];
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i] += lz[p];
            }
        }
        lz[p] = 0;
    }
}
void upd(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
pi query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return mp(INF, 1);
    if (l <= L && R <= r) {
        return st[p];
    }
    return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void chemthan() {
    cin >> n >> m;
    a.resize(n, vi(m));
    vii from(n * m + 1);
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j], from[a[i][j]] = mp(i, j);
    build(1, 1, n * m);
    long long res = 0;
    int ptr = 1;
    vector<vi> adj(n * m + 1);
    FOR(i, 1, n * m + 1) {
        int x = from[i].fi;
        int y = from[i].se;
        upd(1, 1, i, 1, n * m, 1);
        FOR(d, 0, 4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            vi vals;
            if (inside(nx, ny) && ptr <= a[nx][ny] && a[nx][ny] < i) {
                vals.pb(a[nx][ny]);
            }
            sort(all(vals));
            for (int x : vals) {
                while (ptr <= x && findroot(x) == i) {
                    for (int y : adj[ptr]) {
                        makeroot(y);
                        if (findroot(ptr) == y) {
                            cut(ptr);
                        }
                    }
                    makeroot(i);
                    ptr++;
                }
                if (ptr <= x) {
                    makeroot(x);
                    link(x, i);
                    adj[x].pb(i);
                    upd(1, ptr, x, 1, n * m, -1);
                }
            }
        }
        res += query(1, ptr, i, 1, n * m).se;
    }
    cout << res << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}