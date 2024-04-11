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

unsigned char mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define tget(i) ((t[(i) / 8] & mask[(i) % 8]) ? 1 : 0)
#define tset(i, b) t[(i) / 8] = (b) ? (mask[(i) % 8] | t[(i) / 8]) : ((~mask[(i) % 8]) & t[(i) / 8])
#define chr(i) (cs == sizeof(int) ? ((int*) s)[i] : ((unsigned char*) s)[i])
#define isLMS(i) (i > 0 && tget(i) && !tget(i - 1))
void getBuckets(unsigned char* s, int* bkt, int n, int K, int cs, int end) {
    for (int i = 0; i <= K; i++) {
        bkt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bkt[chr(i)]++;
    }
    int sum = 0;
    for (int i = 0; i <= K; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}
void induceSAl(unsigned char* t, int* SA, unsigned char* s, int* bkt, int n, int K, int cs, int end) {
    getBuckets(s, bkt, n, K, cs, end);
    for (int i = 0; i < n; i++) {
        int j = SA[i] - 1;
        if (j >= 0 && !tget(j)) {
            SA[bkt[chr(j)]++] = j;
        }
    }
}
void induceSAs(unsigned char* t, int* SA, unsigned char* s, int* bkt, int n, int K, int cs, int end) {
    getBuckets(s, bkt, n, K, cs, end);
    for (int i = n - 1; i >= 0; i--) {
        int j = SA[i] - 1;
        if (j >= 0 && tget(j)) {
            SA[--bkt[chr(j)]] = j;
        }
    }
}
void buildSA(unsigned char* s, int* SA, int n, int K, int cs) {
    unsigned char* t = (unsigned char*) malloc(n / 8 + 1);
    tset(n - 2, 0);
    tset(n - 1, 1);
    for (int i = n - 3; i >= 0; i--) {
        tset(i, (chr(i) < chr(i + 1) || (chr(i) == chr(i + 1) && tget(i + 1) == 1)) ? 1 : 0);
    }
    int* bkt = (int*) malloc(sizeof(int) * (K + 1));
    getBuckets(s, bkt, n, K, cs, true);
    for (int i = 0; i < n; i++) {
        SA[i] = -1;
    }
    for (int i = 1; i < n; i++) if (isLMS(i)) {
        SA[--bkt[chr(i)]] = i;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, 0);
    induceSAs(t, SA, s, bkt, n, K, cs, 1);
    free(bkt);
    int n1 = 0;
    for (int i = 0; i < n; i++) if (isLMS(SA[i])) {
        SA[n1++] = SA[i];
    }
    for (int i = n1; i < n; i++) {
        SA[i] = -1;
    }
    int name = 0, prev = -1;
    for (int i = 0; i < n1; i++) {
        int pos = SA[i];
        int diff = 0;
        for (int d = 0; d < n; d++)
            if (prev == -1 || chr(pos + d) != chr(prev + d) || tget(pos + d) != tget(prev + d)) {
                diff = 1;
                break;
            }
            else if (d > 0 && (isLMS(pos + d) || isLMS(prev + d))) {
                break;
            }
        if (diff) {
            name++;
            prev = pos;
        }
        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
        SA[n1 + pos] = name - 1;
    }
    for (int i = n - 1, j = n - 1; i >= n1; i--) if (SA[i] >= 0) {
        SA[j--] = SA[i];
    }
    int *SA1 = SA, *s1 = SA + n - n1;
    if (name < n1) {
        buildSA((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
    }
    else {
        for (int i = 0; i < n1; i++) {
            SA1[s1[i]] = i;
        }
    }
    bkt = (int*) malloc(sizeof(int) * (K + 1));
    getBuckets(s, bkt, n, K, cs, 1);
    for (int i = 1, j = 0; i < n; i++) if (isLMS(i)) {
        s1[j++] = i;
    }
    for (int i = 0; i < n1; i++) {
        SA1[i] = s1[SA1[i]];
    }
    for (int i = n1; i < n; i++) {
        SA[i] = -1;
    }
    for (int i = n1 - 1; i >= 0; i--) {
        int j = SA[i];
        SA[i] = -1;
        SA[--bkt[chr(j)]] = j;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, 0);
    induceSAs(t, SA, s, bkt, n, K, cs, 1);
    free(bkt);
    free(t);
}
struct SuffixArray {
    static const int MAXN = 3e5 + 5;
    static const int MAXC = 256;
    static const unsigned char SEP = '$';
    int SA[MAXN], RA[MAXN];
    int Phi[MAXN], PLCP[MAXN];
    int LCP[MAXN];
    int n;
    unsigned char s[MAXN];

    void build(char* t) {
        n = strlen(t);
        for (int i = 0; i < n; i++) {
            s[i] = t[i];
            RA[i] = SA[i] = 0;
            Phi[i] = PLCP[i] = LCP[i] = 0;
        }
        s[n] = 0;
        buildSA(s, SA, n, MAXC, 1);
        for (int i = 0; i < n; i++) {
            RA[SA[i]] = i;
        }
        buildLCP();
    }
    void buildLCP() {
        int L = 0;
        Phi[SA[0]] = -1;
        for (int i = 1; i < n; i++) Phi[SA[i]] = SA[i - 1];
        for (int i = 0; i < n; i++) {
            if (!~Phi[i]) {PLCP[i] = 0; continue;}
            while (s[i + L] == s[Phi[i] + L] && s[i + L] != SEP) L++;
            PLCP[i] = L;
            L = max(L - 1, 0);
        }
        for (int i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
    }
} sa;

template<class T, class cmp = less<T> > struct RMQ {
    int n;
    vector<T> a;
    vector<vector<T> > f;

    T best(T a, T b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int n) {
        this->n = n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    void upd(int u, T x) {
        a[u] = x;
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    T query(int a, int b) {
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int> rmq;

const int maxn = 1e5 + 5;
string s, ss;
int n;
int k[maxn];
string t[maxn];
int pos[maxn];

int findprv(int t, int len) {
    int lo = 0, hi = t;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (rmq.query(mi + 1, t) < len) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    return lo + hi >> 1;
}
int findnxt(int t, int len) {
    int lo = t, hi = sz(ss) - 1;
    while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        if (rmq.query(t + 1, mi) >= len) {
            lo = mi;
        }
        else {
            hi = mi - 1;
        }
    }
    return lo + hi >> 1;
}

void chemthan() {
    cin >> s >> n;
    ss = s + "$";
    FOR(i, 0, n) {
        cin >> k[i] >> t[i];
        pos[i] = sz(ss);
        ss += t[i] + "$";
    }
    sa.build((char *) ss.data());
    rmq.init(sz(ss));
    FOR(i, 0, sz(ss)) {
        rmq.upd(i, sa.LCP[i]);
    }
    rmq.build();
    FOR(i, 0, n) {
        int x = pos[i];
        x = sa.RA[x];
        int lo = findprv(x, sz(t[i]));
        int hi = findnxt(x, sz(t[i]));
        static int vals[maxn];
        int num = 0;
        FOR(j, lo, hi + 1) {
            int p = sa.SA[j];
            if (p < sz(s)) {
                vals[num++] = p;
            }
        }
        if (num < k[i]) {
            cout << -1 << "\n";
            continue;
        }
        sort(vals, vals + num);
        int res = INF;
        FOR(j, 0, num - k[i] + 1) {
            chkmin(res, vals[j + k[i] - 1] - vals[j] + sz(t[i]));
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