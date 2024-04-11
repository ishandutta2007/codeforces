#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 3e5 + 5;
const int mod1 = (int) 1e9 + 7;
const int mod2 = (int) 1e8 + 7;
int n;
vii adj[maxn];
int size[maxn];
int lev[maxn];

int p1[maxn];
int p2[maxn];
int val1[maxn];
int val2[maxn];

multiset<pi>* f[maxn];

int tot[maxn];
int sum[maxn];

void dfs(int u) {
    size[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int w = adj[u][i].se;
        lev[v] = lev[u] + 1;
        val1[v] = (val1[u] + mult(w, p1[lev[u]], mod1)) % mod1;
        val2[v] = (val2[u] + mult(w, p2[lev[u]], mod2)) % mod2;
        dfs(v);
        size[u] += size[v];
    }
}

void dfs2(int u) {
    pi best = mp(0, 0);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        dfs2(v);
        chkmax(best, mp(size[v], v));
    }
    int mx = best.se;
    int ww;
    FOR(i, 0, sz(adj[u])) {
        if (adj[u][i].fi == mx) {
            ww = adj[u][i].se;
            break;
        }
    }
    if (!best.fi) {
        f[u] = new multiset<pi>();
    }
    else {
        f[u] = f[mx];
    }
    if (sz(adj[u])) {
        tot[u] = 1;
    }
    f[u]->insert(mp(val1[u], val2[u]));
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int w = adj[u][i].se;
        if (v != mx) {
            FORall(it, *f[v]) {
                int x1 = it->fi;
                int x2 = it->se;
                submod(x1, mult(w, p1[lev[u]], mod1), mod1);
                submod(x2, mult(w, p2[lev[u]], mod2), mod2);
                addmod(x1, mult(ww, p1[lev[u]], mod1), mod1);
                addmod(x2, mult(ww, p2[lev[u]], mod2), mod2);
                tot[u] += f[u]->count(mp(x1, x2)) > 0;
                f[u]->insert(mp(x1, x2));
            }
        }
    }
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int w = adj[u][i].se;
        if (v != mx) {
            FORall(it, *f[v]) {
                int x1 = it->fi;
                int x2 = it->se;
                f[u]->insert(mp(x1, x2));
                submod(x1, mult(w, p1[lev[u]], mod1), mod1);
                submod(x2, mult(w, p2[lev[u]], mod2), mod2);
                addmod(x1, mult(ww, p1[lev[u]], mod1), mod1);
                addmod(x2, mult(ww, p2[lev[u]], mod2), mod2);
                f[u]->erase(f[u]->find(mp(x1, x2)));
            }
        }
    }
}

void solve() {
    p1[0] = p2[0] = 1;
    FOR(i, 1, maxn) {
        p1[i] = mult(p1[i - 1], 257, mod1);
        p2[i] = mult(p2[i - 1], 257, mod2);
    }
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; string w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w[0]));
    }
    dfs(0), dfs2(0);
    FOR(i, 0, n) {
        sum[lev[i]] += tot[i];
    }
    pi best = mp(INF, INF);
    FOR(i, 0, n) {
        chkmin(best, mp(n - sum[i], i));
    }
    cout << best.fi << "\n" << best.se + 1 << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}