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

int f, T, t2;
int a[2], t[2], p[2];

inline long long func(long long a, long long b, long long c) {
    static pair<long long, long long> vals[3];
    vals[0] = mp(t2, c);
    vals[1] = mp(t[0], a);
    vals[2] = mp(t[1], b);
    if (vals[0].fi > vals[1].fi) swap(vals[0], vals[1]);
    if (vals[0].fi > vals[2].fi) swap(vals[0], vals[2]);
    if (vals[1].fi > vals[2].fi) swap(vals[1], vals[2]);
    long long tot = 0, cur = f;
    FOR(i, 0, 3) {
        long long mn = min(cur, vals[i].se);
        tot += mn * vals[i].fi;
        chkmin(tot, LINF + LINF);
        cur -= mn;
    }
    return tot;
}

inline long long ff(long long x0, long long x1) {
    if (x0 < 0 || x1 < 0) return LINF * 8;
    if (func(x0 * a[0], x1 * a[1], LINF) > T) return LINF * 8;
    return x0 * p[0] + x1 * p[1];
}

void solve() {
    cin >> f >> T >> t2;
    FOR(i, 0, 2) cin >> a[i] >> t[i] >> p[i];
    if (t[0] > t[1]) swap(t[0], t[1]), swap(a[0], a[1]), swap(p[0], p[1]);
    long long ans = LINF * 8;
    for (int x0 = 0; (long long) x0 * a[0] <= f + a[0]; x0++) {
        long long A = (long long) a[1] * (t[1] - t2);
        long long B = T - (long long) x0 * t[0] * a[0] + ((long long) x0 * a[0] - f) * t2;
        if (A) {
            long long C = B / A;
            FOR(dif, -2, 1 + 1) {
                chkmin(ans, ff(x0, C + dif));
            }
        }
        chkmin(ans, ff(x0, 0));
    }
    if (ans == LINF * 8) ans = -1;
    cout << ans << "\n";
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