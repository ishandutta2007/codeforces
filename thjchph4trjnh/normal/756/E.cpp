#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
    #define cout cerr
#endif
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}


const int BASE = 1000000000;
const int NBLOCK = 9;
struct Bigint {
    vector<int> data;
    Bigint() {data.push_back(0);}
    Bigint(long long x) {
        if (!x) data.push_back(0);
        while (x) data.push_back(x % BASE), x /= BASE;
    }
    Bigint(string s);
    void trim() {while (data.size() > 1 && !data.back()) data.pop_back();}
    int& operator[] (int i) {return data[i];}
    int len() {return data.size();}
    int iszero() const {return data.empty() || (data.size() == 1 && !data[0]);}
    long long longValue() const {
        long long res = 0;
        for (int i = data.size() - 1; i >= 0; i--) res = res * BASE + data[i];
        return res;
    }
};
Bigint::Bigint(string s) {
    data.clear(); int pos = 0;
    for (int i = s.size() - 1; i >= pos; i -= NBLOCK) {
        int x = 0;
        for (int j = max(pos, i - NBLOCK + 1); j <= i; j++) x = x * 10 + s[j] - '0';
        data.push_back(x);
    }
    trim();
}
pair<Bigint, int> divmod(Bigint a, int m) {
    long long r = 0;
    for (int i = a.len() - 1; i >= 0; i--) {
        r = r * BASE + a[i];
        a[i] = r / m;
        r %= m;
    }
    a.trim();
    return make_pair(a, (int) r);
}

const int maxn = 300000 + 5;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int dp[maxn];
int ff[maxn];

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    string s; cin >> s;
    Bigint m(s);
    FOR(i, 0, n - 1) {
        if (a[i] > 1) {
            pair<Bigint, Bigint> r = divmod(m, a[i]);
            c[i] = r.se.longValue();
            m = r.fi;
        }
    }
    FOR(i, 0, b[0] + 1) dp[i] = 1;
    int pv = b[0];
    FOR(i, 1, n) {
        int cr = pv / a[i - 1] + b[i];
        FOR(j, 0, pv + 1) {
            if (j >= a[i - 1]) {
                addmod(dp[j], dp[j - a[i - 1]]);
            }
        }
        FOR(j, 0, cr + 1) {
            long long lo = (long long) (j - min(j, b[i])) * a[i - 1] + c[i - 1];
            long long hi = min((long long) pv, (long long) j * a[i - 1] + c[i - 1]);
            c[i - 1] %= a[i - 1];
            if (lo <= hi && hi >= c[i - 1]) {
                hi = (hi - c[i - 1]) / a[i - 1] * a[i - 1] + c[i - 1];
                if (lo < c[i - 1]) {
                    lo = c[i - 1];
                }
                else {
                    lo = (lo - c[i - 1] + a[i - 1] - 1) / a[i - 1] * a[i - 1] + c[i - 1];
                }
                if (lo <= hi) {
                    ff[j] = dp[hi];
                    if (lo >= a[i - 1]) {
                        submod(ff[j], dp[lo - a[i - 1]]);
                    }
                }
            }
        }
        FOR(j, 0, cr + 1) {
            dp[j] = ff[j];
            ff[j] = 0;
        }
        pv = cr;
    }
    if (sz(m.data) >= 10 || m.longValue() > pv) {
        cout << 0 << "\n";
    }
    else {
        cout << dp[m.longValue()] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms\n", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}