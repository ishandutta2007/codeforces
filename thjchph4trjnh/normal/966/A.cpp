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

void chemthan() {
    int n, m, cl, ce, v; cin >> n >> m >> cl >> ce >> v;
    vi vx(cl), vy(ce);
    for (int& x : vx) cin >> x;
    for (int& x : vy) cin >> x;
    int q; cin >> q;
    while (q--) {
        int x[2], y[2];
        FOR(i, 0, 2) cin >> x[i] >> y[i];
        if (y[0] > y[1]) {
            swap(x[0], x[1]);
            swap(y[0], y[1]);
        }
        int k = lower_bound(all(vy), y[0]) - vy.begin();
        if (k < sz(vy) && vy[k] <= y[1]) {
            cout << y[1] - y[0] + (abs(x[0] - x[1]) + v - 1) / v << "\n";
            continue;
        }
        int res = INF;
        if (x[0] == x[1]) {
            res = abs(y[0] - y[1]);
        }
        if (k < sz(vy)) {
            chkmin(res, (abs(x[0] - x[1]) + v - 1) / v + abs(y[0] - vy[k]) + abs(y[1] - vy[k]));
        }
        if (k--) {
            chkmin(res, (abs(x[0] - x[1]) + v - 1) / v + abs(y[0] - vy[k]) + abs(y[1] - vy[k]));
        }
        k = lower_bound(all(vx), y[0]) - vx.begin();
        if (k < sz(vx)) {
            chkmin(res, abs(x[1] - x[0]) + abs(y[0] - vx[k]) + abs(y[1] - vx[k]));
        }
        if (k--) {
            chkmin(res, abs(x[1] - x[0]) + abs(y[0] - vx[k]) + abs(y[1] - vx[k]));
        }
        cout << res << "\n";
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