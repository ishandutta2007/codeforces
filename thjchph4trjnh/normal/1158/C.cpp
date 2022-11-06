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

const int maxn = 5e5 + 5;
int n;
int nxt[maxn];
vi adj[maxn];
int st[maxn << 1];

void upd(int p, int val) {
    for (st[p += n] = val; p > 1; )  p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
int query(int l, int r) {
    int res = -1;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void solve() {
    int test; cin >> test;
    while (test--) {
        cin >> n;
        FOR(i, 0, n) adj[i].clear();
        FOR(i, 0, n) {
            cin >> nxt[i];
            if (nxt[i] != -1) {
                nxt[i]--;
                if (nxt[i] < n) {
                    adj[nxt[i]].pb(i);
                }
            }
        }
        FOR(i, 0, n + n) st[i] = -1;
        FOR(i, 0, n) upd(i, i);
        vi vis(n);
        vi ver;
        function<void(int)> dfs = [&] (int u) {
            vis[u] = 1;
            for (int nu : adj[u]) {
                if (!vis[nu]) {
                    dfs(nu);
                }
            }
            while (1) {
                int nu = query(u + 1, nxt[u] - 1);
                if (nu == -1) break;
                upd(nu, -1);
                if (!vis[nu]) {
                    dfs(nu);
                }
            }
            ver.pb(u);
        };
        FOR(u, 0, n) if (!vis[u]) dfs(u);
        reverse(all(ver));
        vi res(n);
        FOR(i, 0, n) res[ver[i]] = n - i - 1;
        FOR(i, 0, n + n) st[i] = -1;
        FOR(i, 0, n) upd(i, res[i]);
        int found = 0;
        FOR(i, 0, n) if (nxt[i] != -1) {
            if ((nxt[i] < n && res[nxt[i]] < res[i]) || res[i] < query(i + 1, nxt[i] - 1)) {
                found = 1;
                break;
            }
        }
        if (found) {
            cout << -1 << "\n";
        }
        else {
            FOR(i, 0, n) cout << res[i] + 1 << " \n"[i == n - 1];
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