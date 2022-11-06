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
//const int FFTMOD = 119 << 23 | 1;
const int FFTMOD = 1004535809;
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

typedef long long num_t;
namespace CRT {
    num_t res = 0;
    num_t prd = 1;

    void clear() {
        res = 0, prd = 1;
    }
    num_t mul(num_t a, num_t b, num_t p) {
        a %= p, b %= p;
        num_t q = (num_t) ((long double) a * b / p);
        num_t r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
    }
    long long f[2] = {-1, -1};
    template<typename num_t>
    pair<num_t, num_t> euclid(num_t a, num_t b) {
        if (!b) return make_pair(1, 0);
        pair<num_t, num_t> r = euclid(b, a % b);
        return make_pair(r.second, r.first - a / b * r.second);
    }
    void add(num_t p, num_t r, int k) {
        res += mul(r - res % p + p, (~f[k] ? f[k] : f[k] = euclid(prd, p).first) + p, p) * prd;
        prd *= p;
        if (res >= prd) res -= prd;
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];
    vector<vi> b(n, vi(n));
    vector<vi> b2(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) {
        FOR(k, 0, 3) if (k != i && k != j) {
            b[i][j] = mult(a[i][k], inv(a[j][k]));
            b2[i][j] = mult(a[i][k], inv(a[j][k], FFTMOD), FFTMOD);
            break;
        }
    }
    FOR(i, 0, n) {
        int j = (i + 1) % n;
        CRT::clear();
        CRT::add(MOD, mult(a[i][j], b[i][j]), 0);
        CRT::add(FFTMOD, mult(a[i][j], b2[i][j], FFTMOD), 1);
        cout << isqrt(CRT::res % ((long long) MOD * FFTMOD)) << " \n"[i == n - 1];
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