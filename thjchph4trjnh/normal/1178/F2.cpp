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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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

template<class num_t, class cmp = less<num_t> >
struct RMQ {
    int n;
    vector<num_t> a;
    vector<vector<num_t> > f;

    inline num_t best(const num_t& a, const num_t& b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int _n) {
        n = _n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        a.shrink_to_fit(), f.shrink_to_fit();
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    num_t& operator [] (int u) {
        assert(u < (int) a.size());
        return a[u];
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    num_t query(int a, int b) {
        assert(a <= b);
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int> rmq;

void solve() {
    int n, m; cin >> n >> m;
    vi c(m);
    FOR(i, 0, m) cin >> c[i];
    uni(c);
    vi l(n + 1, +INF), r(n + 1, -INF);
    m = sz(c);
    rmq.init(m);
    FOR(i, 0, m) {
        rmq[i] = c[i];
    }
    rmq.build();
    vector<vi> g(n + 1);
    FOR(i, 0, m) {
        g[c[i]].pb(i);
    }
    vi fen(m + 1);
    auto upd = [&] (int p, int val) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            fen[p] += val;
        }
    };
    auto query = [&] (int p) {
        p++;
        int res = 0;
        for (; 0 < p; p -= p & -p) {
            res += fen[p];
        }
        return res;
    };
    FOR(i, 1, n + 1) {
        FOR(j, 0, sz(g[i]) - 1) {
            int l = g[i][j];
            int r = g[i][j + 1];
            if (query(r) - query(l)) {
                cout << 0 << "\n";
                return;
            }
        }
        for (int x : g[i]) {
            upd(x, 1);
        }
    }
    FOR(i, 0, m) {
        chkmin(l[c[i]], i);
        chkmax(r[c[i]], i);
    }
    FOR(i, 1, n + 1) {
        l[i] <<= 1;
        r[i] <<= 1;
        r[i] |= 1;
    }
    vi dc;
    FOR(i, 1, n + 1) {
        dc.pb(l[i]);
        dc.pb(r[i]);
    }
    sort(all(dc)), uni(dc);
    m = sz(dc);
    c.resize(m);
    FOR(i, 1, n + 1) {
        l[i] = lower_bound(all(dc), l[i]) - dc.begin();
        r[i] = lower_bound(all(dc), r[i]) - dc.begin();
        c[l[i]] = c[r[i]] = i;
    }
    vector<vi> f(m, vi(m));
    FOR(i, 0, m) {
        int mn = INF, cnt = 0;
        FOR(j, i, m) {
            f[i][j] = rmq.query(dc[i] / 2, dc[j] / 2);
        }
    }
    vector<vi> dp(m, vi(m, -1));
    function<int(int, int)> calc = [&] (int l, int r) {
        if (r < l) return 1;
        int& res = dp[l][r];
        if (~res) return res;
        res = 0;
        pi mn = mp(INF, INF);
        FOR(i, l, r + 1) {
            chkmin(mn, mp(c[i], i));
        }
        if (f[l][r] < mn.fi) {
            FOR(i, l, r - 1) {
                if (f[i][i + 1] < mn.fi) {
                    addmod(res, mult(calc(l, i), calc(i + 1, r)));
                    break;
                }
            }
            return res;
        }
        int lo = +INF, hi = -INF;
        FOR(i, l, r + 1) if (c[i] == mn.fi) {
            chkmin(lo, i);
            chkmax(hi, i);
        }
        if (lo == hi) {
            return 0;
        }
        int x = 0, y = 0;
        FOR(i, l, lo + 1) {
            addmod(x, mult(calc(l, i - 1), calc(i, lo - 1)));
        }
        FOR(i, hi, r + 1) {
            addmod(y, mult(calc(hi + 1, i), calc(i + 1, r)));
        }
        res = mult(calc(lo + 1, hi - 1), mult(x, y));
        return res;
    };
    cout << calc(0, m - 1) << "\n";
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