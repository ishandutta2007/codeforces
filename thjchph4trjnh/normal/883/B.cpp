#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e5 + 5;
int n, m, k;
int r[maxn];
vi adj[maxn];
vi radj[maxn];
vi ver;
int vis[maxn];
int b[maxn];

void dfs(int u) {
    vis[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
    ver.pb(u);
}

int num;
void rdfs(int u) {
    vis[u] = 1, num++;
    FOR(i, 0, sz(radj[u])) {
        int v = radj[u][i];
        if (!vis[v]) {
            rdfs(v);
        }
    }
}

int st[maxn << 1];
void upd(int p, int val) {
    for (st[p += maxn] = 1; p > 1; ) p >>= 1, st[p] = st[p << 1] + st[p << 1 | 1];
}
int query(int l, int r) {
    int res = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += st[l++];
        if (r & 1) res += st[--r];
    }
    return res;
}

int cmp(int u, int v) {
    if (b[u] != b[v]) {
        return b[u]< b[v];
    }
    return u < v;
}

void solve() {
    cin >> n >> m >> k;
    FOR(i, 0, n) cin >> r[i];
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    FOR(i, 0, n) if (!vis[i]) dfs(i);
    fill_n(vis, n, 0);
    FORd(i, n, 0) {
        int u = ver[i];
        if (!vis[u]) {
            num = 0, rdfs(u);
            if (num > 1) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    FOR(i, 0, n) {
        if (r[i]) {
            b[i] = r[i];
        }
        else {
            b[i] = k;
        }
    }
    FORd(i, n, 0) {
        int u = ver[i];
        FOR(j, 0, sz(adj[u])) {
            int v = adj[u][j];
            chkmin(b[v], b[u] - 1);
            if (b[v] <= 0) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    static int f[maxn];
    static int ans[maxn];
    FOR(i, 0, n) if (r[i]) {
        upd(r[i], 1);
        ans[i] = r[i];
    }
    sort(all(ver), cmp);
    FOR(i, 0, n) {
        int u = ver[i];
        if (!r[u]) {
            int lo = 1;
            for (int v : adj[u]) {
                chkmax(lo, ans[v] + 1);
            }
            int hi = b[u];
            while (lo < hi) {
                int mi = lo + hi >> 1;
                if (query(lo, mi) == mi - lo + 1) {
                    lo = mi + 1;
                }
                else {
                    hi = mi;
                }
            }
            int mi = lo + hi >> 1;
            ans[u] = mi;
            upd(mi, 1);
        }
    }
    FOR(u, 0, n) {
        if (ans[u] <= 0 || ans[u] > k) {
            cout << -1 << "\n";
            return;
        }
        for (int v : adj[u]) {
            if (ans[u] <= ans[v]) {
                cout << -1 << "\n";
                return;
            }
        }
        if (r[u] && ans[u] != r[u]) {
            cout << -1 << "\n";
            return;
        }
    }
    if (query(1, k) < k) {
        cout << -1 << "\n";
        return;
    }
    FOR(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}