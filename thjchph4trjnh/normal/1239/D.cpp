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
inline int mrand() {return abs((int) mt());}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void solve() {
    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        vector<vi> adj(n);
        vector<vi> radj(n);
        FOR(i, 0, m) {
            int u, v; cin >> u >> v; u--, v--;
            if (u ^ v) {
                adj[u].pb(v);
                radj[v].pb(u);
            }
        }
        vi vis(n);
        vi ver;
        function<void(int)> dfs = [&] (int u) {
            vis[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
            ver.pb(u);
        };
        FOR(u, 0, n) if (!vis[u]) {
            dfs(u);
        }
        map<int, vi> hs;
        map<int, int> ff;
        map<int, int> gg;
        function<void(int, int)> rdfs = [&] (int u, int cnt) {
            hs[cnt].pb(u);
            ff[u] = cnt;
            vis[u] = 1;
            for (int v : radj[u]) {
                if (!vis[v]) {
                    rdfs(v, cnt);
                }
            }
        };
        reverse(all(ver));
        FOR(u, 0, n) vis[u] = 0;
        int cnt = 0;
        for (int u : ver) if (!vis[u]) {
            rdfs(u, cnt++);
        }
        FOR(u, 0, n) {
            for (int v : adj[u]) {
                if (ff[u] ^ ff[v]) {
                    gg[ff[u]] = 1;
                }
            }
        }
        int found = 0;
        for (auto e : hs) if (!gg[e.fi]) {
            vi vis(n);
            for (auto u : e.se) {
                vis[u] = 1;
            }
            vi v1, v2;
            FOR(i, 0, n) {
                if (vis[i]) {
                    v1.pb(i);
                }
                else {
                    v2.pb(i);
                }
            }
            if (sz(v1) && sz(v2)) {
                cout << "Yes\n";
                cout << sz(v1) << " " << sz(v2) << "\n";
                FOR(i, 0, sz(v1)) cout << v1[i] + 1 << " \n"[i == sz(v1) - 1];
                FOR(i, 0, sz(v2)) cout << v2[i] + 1 << " \n"[i == sz(v2) - 1];
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "No\n";
        }
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}