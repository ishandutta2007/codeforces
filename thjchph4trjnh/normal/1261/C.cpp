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
 
void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 2);
    FOR(i, 0, n) {
        cin >> a[i + 1];
        a[i + 1] = "." + a[i + 1] + ".";
    }
    FOR(i, 0, m + 2) {
        a[0] += ".";
        a[n + 1] += ".";
    }
    vector<vi> d(n + 2, vi(m + 2, INF));
    vector<vi> d2(n + 2, vi(m + 2, INF));
    auto check = [&] (int k, int flag) {
        static int que[12345678];
        int qh = 0, qe = 0;
        FOR(i, 0, n + 2) FOR(j, 0, m + 2) d[i][j] = d2[i][j] = INF;
        FOR(i, 0, n + 2) FOR(j, 0, m + 2) {
            if (a[i][j] == '.') {
                d[i][j] = 0;
                que[qe++] = i;
                que[qe++] = j;
            }
        }
        while (qh < qe) {
            int u = que[qh++];
            int v = que[qh++];
            if (d[u][v] == k) continue;
            auto inside = [&] (int u, int v) {
                if (!(0 <= u && u < n + 2)) return 0;
                if (!(0 <= v && v < m + 2)) return 0;
                return 1;
            };
            FOR(i, -1, 1 + 1) FOR(j, -1, 1 + 1) if (i || j) {
                int nu = u + i;
                int nv = v + j;
                if (inside(nu, nv) && chkmin(d[nu][nv], d[u][v] + 1)) {
                    que[qe++] = nu;
                    que[qe++] = nv;
                }
            }
        }
        qh = qe = 0;
        FOR(i, 0, n + 2) FOR(j, 0, m + 2) {
            if (d[i][j] == INF && a[i][j] == 'X') {
                d2[i][j] = 0;
                que[qe++] = i, que[qe++] = j;
            }
        }
        while (qh < qe) {
            int u = que[qh++];
            int v = que[qh++];
            if (d2[u][v] == k) continue;
            auto inside = [&] (int u, int v) {
                if (!(0 <= u && u < n + 2)) return 0;
                if (!(0 <= v && v < m + 2)) return 0;
                return 1;
            };
            FOR(i, -1, 1 + 1) FOR(j, -1, 1 + 1) if (i || j) {
                int nu = u + i;
                int nv = v + j;
                if (inside(nu, nv) && chkmin(d2[nu][nv], d2[u][v] + 1)) {
                    que[qe++] = nu;
                    que[qe++] = nv;
                }
            }
        }
        if (flag) {
            FOR(i, 1, n + 1) {
                FOR(j, 1, m + 1) {
                    if (d[i][j] == INF && a[i][j] == 'X') {
                        cout << "X";
                    }
                    else {
                        cout << ".";
                    }
                }
                cout << "\n";
            }
        }
        FOR(i, 0, n + 2) FOR(j, 0, m + 2) {
            if (a[i][j] == 'X' && d2[i][j] == INF) {
                return 0;
            }
        }
        return 1;
    };
    int lo = 0, hi = (int) 1e6;
    while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        if (check(mi, 0)) {
            lo = mi;
        }
        else {
            hi = mi - 1;
        }
    }
    int mi = lo + hi >> 1;
    cout << mi << "\n";
    check(mi, 1);
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