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

template<typename num_t>
struct RangeFenwick {
    int n;
    vector<num_t> fen[2];
    RangeFenwick(int n) {
        this->n = n;
        fen[0].resize(n + 1);
        fen[1].resize(n + 1);
    }
    void upd(int p, num_t val) {
        p++;
        assert(0 < p);
        for (int pp = p; pp <= n; pp += pp & -pp) {
            fen[0][pp] += val;
            fen[1][pp] += val * p;
        }
    }
    void upd(int l, int r, num_t val) {
        upd(l, +val), upd(r + 1, -val);
    }
    num_t query(int p) {
        p++;
        assert(p <= n);
        num_t res = 0;
        for (int pp = p; pp > 0; pp -= pp & -pp) {
            res += fen[0][pp] * (p + 1);
            res -= fen[1][pp];
        }
        return res;
    }
    num_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int, int>> vals;
    vi dc;
    FOR(i, 0, n) {
        int x, y, z, t; cin >> x >> y >> z >> t;
        vals.pb({x, y, z, t});
        dc.pb(x), dc.pb(y), dc.pb(z), dc.pb(t);
    }
    sort(all(dc)), uni(dc);
    for (auto& e : vals) {
        get<0>(e) = lower_bound(all(dc), get<0>(e)) - dc.begin();
        get<1>(e) = lower_bound(all(dc), get<1>(e)) - dc.begin();
        get<2>(e) = lower_bound(all(dc), get<2>(e)) - dc.begin();
        get<3>(e) = lower_bound(all(dc), get<3>(e)) - dc.begin();
    }
    FOR(it, 0, 2) {
        RangeFenwick<int> fen(sz(dc));
        for (auto& e : vals) {
            swap(get<0>(e), get<2>(e));
            swap(get<1>(e), get<3>(e));
        }
        sort(all(vals));
        auto vals2 = vals;
        sort(all(vals2), [&] (tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
                return get<1>(a) < get<1>(b);
                }
            );
        int ptr = 0;
        for (auto e : vals) {
            while (ptr < sz(vals2) && get<1>(vals2[ptr]) < get<0>(e)) {
                int z = get<2>(vals2[ptr]);
                int t = get<3>(vals2[ptr]);
                fen.upd(z, t, 1);
                ptr++;
            }
            int z = get<2>(e);
            int t = get<3>(e);
            if (fen.query(z, t)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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