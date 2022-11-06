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

const int maxn = 1e6 + 5;
int n;
long long l;
long long a[maxn];
long long b[maxn];

int st[maxn << 1];

void upd(int p, int val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}

int query(int l, int r) {
    int res = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}


int check(int mi) {
    fill_n(st, maxn << 1, -INF);
    vector<pair<long long, long long> > vals;
    FOR(i, 0, n) {
        long long u = a[i] - mi + l - 1;
        long long v = a[i] + mi + l;
        vals.pb(mp(u, v));
    }
    FOR(i, 0, n) {
        long long u = a[i] - mi + l - 1 + l;
        long long v = a[i] + mi + l + l;
        vals.pb(mp(u, v));
    }
    vector<long long> vv;
    FOR(i, 0, n) {
        vv.pb(b[i]);
    }
    FOR(i, 0, n) {
        vv.pb(b[i] + l);
    }
    FOR(i, 0, n) {
        vv.pb(b[i] + l + l);
    }
    FOR(i, 0, n) {
        vv.pb(b[i] + l + l + l);
    }
    int ptr = 0;
    FOR(i, 0, sz(vals)) {
        long long u = vals[i].fi;
        long long v = vals[i].se;
        while (ptr <= i - n) {
            ptr++;
        }
        int k = upper_bound(all(vv), u) - vv.begin();
        upd(i, k - i);
        k = upper_bound(all(vv), v) - vv.begin();
        if (k - i - 1 < query(ptr, i)) {
            return 0;
        }
    }
    return 1;
}

void thjchph4trjnh() {
    cin >> n >> l;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    sort(a, a + n), sort(b, b + n);
    int lo = 0, hi = l / 2;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!check(mi)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    cout << (lo + hi >> 1) << "\n";
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