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

void solve() {
    int n; cin >> n;
    vector<vi> a(n);
    vector<vii> nxt(n);
    map<long long, pi> hs;
    long long sum = 0;
    FOR(i, 0, n) {
        int k; cin >> k;
        a[i].resize(k);
        nxt[i].resize(k, mp(-1, -1));
        FOR(j, 0, k) cin >> a[i][j], hs[a[i][j]] = mp(i, j), sum += a[i][j];
    }
    if (sum % n) {
        cout << "NO\n";
        return;
    }
    sum /= n;
    FOR(i, 0, n) {
        long long tot = 0;
        FOR(j, 0, sz(a[i])) {
            tot += a[i][j];
        }
        FOR(j, 0, sz(a[i])) {
            long long dif = sum - tot;
            if (hs.count(a[i][j] + dif)) {
                nxt[i][j] = hs[a[i][j] + dif];
            }
        }
    }
    vector<vii> f(1 << n);
    FOR(i, 0, n) {
        FOR(j, 0, sz(a[i])) {
            vi vis(n);
            vii path;
            int x = i, y = j;
            int found = 0;
            int msk = 0;
            while (!vis[x]) {
                msk |= 1 << x;
                path.pb({x, y});
                vis[x] = 1;
                if (nxt[x][y] == mp(-1, -1)) {
                    break;
                }
                int nx, ny;
                tie(nx, ny) = nxt[x][y];
                x = nx, y = ny;
                if (mp(x, y) == mp(i, j)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                f[msk] = path;
            }
        }
    }
    vi dp(1 << n);
    vi rb(1 << n);
    dp[0] = 1;
    FOR(msk, 1, 1 << n) {
        for (int sub = msk; 0 < sub; sub = sub - 1 & msk) {
            if (sz(f[sub]) && dp[msk ^ sub]) {
                dp[msk] = 1;
                rb[msk] = sub;
                break;
            }
        }
    }
    if (!dp[(1 << n) - 1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int msk = (1 << n) - 1;
    vector<tuple<int, int, int>> res;
    while (msk) {
        int t = rb[msk];
        FOR(i, 0, sz(f[t])) {
            int j = (i + 1) % sz(f[t]);
            int x1 = f[t][i].fi;
            int y1 = f[t][i].se;
            int x2 = f[t][j].fi;
            int y2 = f[t][j].se;
            res.pb({x2, a[x2][y2], x1});
        }
        msk ^= t;
    }
    sort(all(res));
    FOR(i, 0, n) {
        cout << get<1>(res[i]) << " " << get<2>(res[i]) + 1 << "\n";
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