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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e6 + 5;
int n;
long long k;
long long a[maxn];
long long b[maxn];
int num;
long long pr[maxn];

void join(vector<pair<long long, int> >& a, vector<pair<long long, int> >& b) {
    for (auto it : b) {
        a.pb(it);
    }
    sort(all(a)), uni(a);
    while (sz(a) > num) a.pop_back();
}

void solve() {
    cin >> n >> k;
    long long g = 0;
    FOR(i, 0, n) cin >> a[i], g = __gcd(g, a[i]);
    FOR(i, 0, n) cin >> b[i];

    map<long long, int> hs;
    for (int i = 2; (long long) i * i <= g; i++) {
        while (g % i == 0) hs[i]++, g /= i;
    }
    if (g > 1) hs[g]++;
    for (auto it : hs) {
        pr[num++] = it.fi;
    }

    auto fix = [&] (long long t) {
        long long res = 1;
        FOR(i, 0, num) {
            if (t % pr[i] == 0) {
                res *= pr[i];
            }
        }
        return res;
    };

    static long long ft[maxn][11];
    map<long long, vector<pair<long long, int> > > hs2;
    priority_queue<pair<pair<long long, long long>, int> > heap;
    FOR(i, 0, n) {
        int ptr = 0;
        long long t = 1;
        for (auto it : hs) {
            ft[i][ptr] = 1;
            while (a[i] % it.fi == 0) ft[i][ptr] *= it.fi, a[i] /= it.fi;
            t *= ft[i][ptr];
            ptr++;
        }
        int l = i;
        if (t <= k) {
            t = fix(t);
            l = n;
        }
        if (!hs2.count(t)) {
            heap.push(mp(mp(fix(t), t), l));
        }
        hs2[t].pb(mp(b[i], i));
    }
    FOR(i, 0, num) ft[n][i] = pr[i];

    for (auto& it : hs2) {
        sort(all(it.se)), uni(it.se);
        while (sz(it.se) > num) it.se.pop_back();
    }

    static int used[maxn];
    while (sz(heap)) {
        long long t = heap.top().fi.se;
        int u = heap.top().se;
        heap.pop();
        FOR(i, 0, num) if (ft[u][i] > 1 && t % ft[u][i] == 0) {
            long long nt = t / ft[u][i];
            int nu = u;
            if (nt <= k) {
                nt = fix(nt);
                nu = n;
            }
            if (!hs2.count(nt)) {
                heap.push(mp(mp(fix(nt), nt), nu));
                hs2[nt] = hs2[t];
            }
            else {
                join(hs2[nt], hs2[t]);
            }
        }
        if (t <= k) {
            for (auto it : hs2[t]) {
                used[it.se] = 1;
            }
        }
        hs2[t].clear();
    }
    vi ver;
    FOR(i, 0, n) if (used[i]) ver.pb(i);

    static vi ff[maxn / 10];
    static long long gg[maxn / 10];
    FOR(i, 0, sz(ver)) {
        int u = ver[i];
        static long long x[1 << 11];
        x[0] = 1;
        FOR(msk, 1, 1 << num) {
            int d = __lg(msk);
            x[msk] = x[msk ^ (1 << d)] * ft[u][d];
        }
        gg[i] = b[u];
        FOR(msk, 1, 1 << num) if (x[msk] <= k) {
            int found = 0;
            FOR(i, 0, num) if (!bit(msk, i)) {
                int nmsk = msk ^ (1 << i);
                if (x[nmsk] <= k) {
                    found = 1;
                }
            }
            if (!found) {
                ff[i].pb(msk);
            }
        }
    }

    vector<vector<vector<long long> > > dp;
    dp.resize(sz(ver) + 1);
    for (auto& dp1 : dp) {
        dp1.resize(1 << num);
        for (auto& dp2 : dp1) {
            dp2.resize(num + 1, LINF);
        }
    }
    dp[0][0][0] = 0;
    FOR(i, 0, sz(ver)) FOR(msk, 0, 1 << num) FOR(cnt, 0, num + 1) {
        if (cnt < num) {
            for (int nmsk : ff[i]) {
                chkmin(dp[i + 1][msk | nmsk][cnt + 1], dp[i][msk][cnt] + gg[i]);
            }
        }
        chkmin(dp[i + 1][msk][cnt], dp[i][msk][cnt]);
    }
    long long res = LINF;
    FOR(cnt, 0, num + 1) {
        if (dp[sz(ver)][(1 << num) - 1][cnt] < LINF) {
            chkmin(res, dp[sz(ver)][(1 << num) - 1][cnt] * cnt);
        }
    }
    if (res == LINF) res = -1;
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}