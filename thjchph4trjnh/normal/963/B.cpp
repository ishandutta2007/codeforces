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
int n;
vi adj[maxn];
int par[maxn];
int size[maxn];
int f[maxn];

void dfs(int u, int p) {
    size[u] = 1;
    par[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) {
        int u; cin >> u; u--;
        if (u != -1) {
            adj[u].pb(i);
            adj[i].pb(u);
        }
    }
    if (!(n & 1)) {
        cout << "NO\n";
        return;
    }
    dfs(0, -1);
    FOR(u, 0, n) {
        int tot = 0;
        for (int v : adj[u]) {
            if (v != par[u]) {
                if (!(size[v] & 1)) {
                    f[u]++;
                }
                tot += size[v];
            }
        }
        tot = n - tot - 1;
        if (!(tot & 1) && tot) {
            f[u]++;
        }
    }
    static int deg[maxn];
    static int rem[maxn];
    FOR(u, 0, n) deg[u] = sz(adj[u]);
    set<int> st;
    FOR(u, 0, n) {
        if (!f[u] && !(deg[u] & 1)) {
            st.insert(u);
        }
    }
    vi res;
    while (sz(st)) {
        int u = *st.begin();
        st.erase(u);
        if (deg[u] & 1) {
            continue;
        }
        res.pb(u);
        rem[u] = 1;
        for (int v : adj[u]) {
            deg[v]--;
            f[v]--;
            if (!f[v] && !rem[v] && !(deg[v] & 1)) {
                st.insert(v);
            }
        }
    }
    if (sz(res) != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int u : res) {
        cout << u + 1 << "\n";
    }
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