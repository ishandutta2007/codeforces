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
int x[maxn][2];
int y[maxn][2];
int rem[maxn];
int f[maxn];

priority_queue<int> v[maxn << 2];
int mx[maxn << 3];
int mn[maxn << 3];

void pull(int p) {
    while (sz(v[p]) && rem[v[p].top()]) v[p].pop();
    int t = !sz(v[p]) ? -1 : v[p].top();
    if (t <= max(mx[p << 1], mx[p << 1 | 1])) {
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }
    else {
        if (f[t] || t < min(mn[p << 1], mn[p << 1 | 1])) {
            mx[p] = -1;
        }
        else {
            mx[p] = t;
        }

    }
    mn[p] = max(t, min(mn[p << 1], mn[p << 1 | 1]));
}
void upd(int p, int l, int r, int L, int R, int id) {
    if (R <= l || r <= L) return;
    if (l <= L && R <= r) {
        v[p].push(id);
        pull(p);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, id);
    upd(p << 1 | 1, l, r, L + R >> 1, R, id);
    pull(p);
}
void upd(int p, int l, int r, int L, int R) {
    if (R <= l || r <= L) return;
    if (l <= L && R <= r) {
        pull(p);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1);
    upd(p << 1 | 1, l, r, L + R >> 1, R);
    pull(p);
}

void thjchph4trjnh() {
    cin >> n;
    vi dcx, dcy;
    FOR(i, 0, n) {
        FOR(j, 0, 2) {
            cin >> x[i][j] >> y[i][j];
            dcx.pb(x[i][j]);
            dcy.pb(y[i][j]);
        }
    }
    sort(all(dcx)), uni(dcx);
    sort(all(dcy)), uni(dcy);
    static vii events[maxn];
    FOR(i, 0, n) {
        FOR(j, 0, 2) {
            x[i][j] = lower_bound(all(dcx), x[i][j]) - dcx.begin();
            x[i][j] <<= 1;
            y[i][j] = lower_bound(all(dcy), y[i][j]) - dcy.begin();
        }
        events[x[i][0]].pb(mp(i, 0));
        events[x[i][1] + 1].pb(mp(i, 1));
    }
    FOR(i, 0, maxn << 3) mx[i] = -1;
    FOR(i, 0, maxn) {
        for (pi e : events[i]) {
            int ix = e.fi;
            if (!e.se) {
                upd(1, y[ix][0], y[ix][1], 0, maxn - 1, ix + 1);
            }
            else {
                rem[ix + 1] = 1;
                upd(1, y[ix][0], y[ix][1], 0, maxn - 1);
            }
        }
        while (mx[1] > 0) {
            int ix = mx[1] - 1;
            f[ix + 1] = 1;
            upd(1, y[ix][0], y[ix][1], 0, maxn - 1);
        }
    }
    cout << accumulate(f, f + maxn, 1) << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    thjchph4trjnh();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}