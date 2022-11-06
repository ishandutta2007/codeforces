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

const int maxn = 4e5 + 5;
int n;
long long w[maxn];
long long h[maxn];
long long c[maxn];

void chemthan() {
    cin >> n;
    vector<long long> dcw, dch;
    FOR(i, 0, n) {
        cin >> w[i] >> h[i] >> c[i];
        dcw.pb(w[i]);
        dch.pb(h[i]);
    }
    sort(all(dcw)), uni(dcw);
    sort(all(dch)), uni(dch);
    if ((long long) sz(dcw) * sz(dch) != n) {
        cout << 0 << "\n";
        return;
    }
    int x = sz(dcw), y = sz(dch);
    static vi vx[maxn];
    static vi vy[maxn];
    FOR(i, 0, n) {
        int u = lower_bound(all(dcw), w[i]) - dcw.begin();
        int v = lower_bound(all(dch), h[i]) - dch.begin();
        vx[u].pb(v);
        vy[v].pb(u);
    }
    FOR(i, 0, x) {
        if (sz(vx[i]) != y) {
            cout << 0 << "\n";
            return;
        }
    }
    FOR(i, 0, y) {
        if (sz(vy[i]) != x) {
            cout << 0 << "\n";
            return;
        }
    }
    static long long fx[maxn];
    static long long fy[maxn];
    vector<vector<long long> > vals(x, vector<long long>(y));
    FOR(i, 0, n) {
        int u = lower_bound(all(dcw), w[i]) - dcw.begin();
        int v = lower_bound(all(dch), h[i]) - dch.begin();
        vals[u][v] = c[i];
    }
    long long gx = 0, gy = 0;
    FOR(i, 0, x) {
        gy = __gcd(gy, vals[i][0]);
    }
    FOR(i, 0, y) {
        gx = __gcd(gx, vals[0][i]);
    }
    auto cmp = [&] (long long a, long long b, long long c, long long d) {
        long double del = (long double) a * d - (long double) b * c;
        if (del > 1e18) return 0;
        return a * d - b * c == 0 ? 1 : 0;
    };
    FOR(i, 0, x) FOR(j, 0, y) {
        if (!cmp(vals[i][j], vals[i][0], vals[0][j], vals[0][0])) {
            cout << 0 << "\n";
            return;
        }
        if (!cmp(vals[i][j], vals[0][j], vals[i][0], vals[0][0])) {
            cout << 0 << "\n";
            return;
        }
    }
    auto check = [&] (long long k) {
        long long kk = vals[0][0] / k;
        return gx % k == 0 && gy % kk == 0;
    };
    int res = 0;
    for (int k = 1; (long long) k * k <= vals[0][0]; k++) if (vals[0][0] % k == 0) {
        if (check(k)) {
            res++;
        }
        if ((long long) k * k < vals[0][0] && check(vals[0][0] / k)) {
            res++;
        }
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