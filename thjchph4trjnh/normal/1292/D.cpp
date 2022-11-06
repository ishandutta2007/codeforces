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
    int n; cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int mx = *max_element(all(a)) + 5;
    vi sp(mx);
    FOR(i, 1, mx) sp[i] = i;
    FOR(i, 2, mx) if (sp[i] == i) {
        for (int j = i + i; j < mx; j += i) {
            chkmin(sp[j], i);
        }
    }
    auto calc = [&] (int k) {
        vector<int> res;
        FOR(i, 2, mx) if (sp[i] == i) {
            int t = k, r = 0;
            while (t) r += t / i, t /= i;
            res.pb(r);
        }
        reverse(all(res));
        return res;
    };
    auto lca = [&] (vi& v1, vi& v2) {
        vi res(sz(v1));
        FOR(i, 0, sz(v1)) {
            res[i] = min(v1[i], v2[i]);
            if (v1[i] != v2[i]) {
                break;
            }
        }
        return res;
    };
    auto isanc = [&] (vi& a, vi& u) {
        return lca(a, u) == a;
    };
    auto dist = [&] (vi& a, vi& u) {
        int res = 0;
        FOR(i, 0, sz(a)) {
            res += u[i] - a[i];
        }
        return res;
    };
    vector<vi> vals;
    FOR(i, 1, mx) {
        vals.pb(calc(i));
    }
    sort(all(vals));
    FORd(i, sz(vals) - 1, 0) {
        vals.pb(lca(vals[i], vals[i + 1]));
    }
    sort(all(vals)), uni(vals);
    auto ff = [&] (vi& v) {
        return lower_bound(all(vals), v) - vals.begin();
    };
    stack<vi> stk;
    stk.push(vals[0]);
    int c = sz(vals);
    vector<vii> adj(c);
    vi w(c);
    FOR(i, 1, sz(vals)) {
        while (!isanc(stk.top(), vals[i])) {
            stk.pop();
        }
        auto a = stk.top();
        auto u = vals[i];
        stk.push(u);
        int ia = ff(a);
        int iu = ff(u);
        int d = dist(a, u);
        adj[ia].pb({iu, d});
        adj[iu].pb({ia, d});
    }
    vi cnt(mx);
    FOR(i, 0, n) {
        cnt[a[i]]++;
    }
    FOR(i, 0, mx) {
        auto v = calc(i);
        int u = ff(v);
        w[u] += cnt[i];
    }
    vector<long long> x(c);
    vector<long long> d(c);
    function<void(int, int)> dfs = [&] (int u, int p) {
        x[u] = w[u];
        for (auto e : adj[u]) {
            int v = e.fi;
            int w = e.se;
            if (v != p) {
                d[v] = d[u] + w;
                dfs(v, u);
                x[u] += x[v];
            }
        }
    };
    dfs(0, -1);
    int u = 0, p = -1;
    while (1) {
        pair<long long, int> best;
        for (auto e : adj[u]) {
            int v = e.fi;
            if (v != p) {
                chkmax(best, mp(x[v], v));
            }
        }
        if (best.fi + best.fi <= x[0]) {
            break;
        }
        p = u, u = best.se;
    }
    d[u] = 0;
    dfs(u, -1);
    long long res = 0;
    FOR(i, 0, c) {
        res += w[i] * d[i];
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}