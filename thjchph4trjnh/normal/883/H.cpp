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

const int maxn = 4e5 + 5;
const int maxc = 256;
int n;
string s;
int cnt[maxc];

string makepara(string s) {
    static int f[maxc];
    fill_n(f, maxc, 0);
    FOR(i, 0, sz(s)) {
        int c = s[i];
        f[c]++;
    }
    string z1, z2, z3;
    FOR(i, 0, maxc) {
        if (f[i] & 1) {
            z3 += char(i);
            f[i]--;
        }
        while (f[i]) {
            z1 += char(i);
            f[i]--;
            if (f[i]) {
                z2 += char(i);
                f[i]--;
            }
        }
    }
    reverse(all(z2));
    return z1 + z3 + z2;
}

void solve() {
    cin >> n >> s;
    FOR(i, 0, n) {
        int c = s[i];
        cnt[c]++;
    }
    int flag = 0, z = 0;
    FOR(i, 0, maxc) {
        if (cnt[i] & 1) {
            flag = 1;
            z++;
        }
    }
    int res = n;
    for (int num = 1; num <= n; num++) if (n % num == 0) {
        int len = n / num;
        if (!(len & 1)) {
            if (!flag) {
                chkmin(res, num);
            }
        }
        else {
            if (!(num + z & 1) && num >= z) {
                chkmin(res, num);
            }
        }
    }
    int len = n / res;
    vector<string> vs(res);
    if (!(len & 1)) {
        int ptr = 0;
        FOR(i, 0, sz(vs)) {
            while (sz(vs[i]) < len) {
                while (!cnt[ptr]) ptr++;
                vs[i] += char(ptr);
                cnt[ptr]--;
            }
        }
    }
    else {
        vi tmp;
        FOR(i, 0, maxc) if (cnt[i] & 1) {
            cnt[i]--;
            tmp.pb(i);
        }
        int ptr = 0;
        while (sz(tmp) < res) {
            while (!cnt[ptr]) ptr++;
            tmp.pb(ptr);
            cnt[ptr]--;
        }
        FOR(i, 0, sz(vs)) {
            vs[i] += char(tmp[i]);
        }
        FOR(i, 0, sz(vs)) {
            while (sz(vs[i]) < len) {
                while (!cnt[ptr]) ptr++;
                vs[i] += char(ptr);
                cnt[ptr]--;
            }
        }
    }
    cout << res << "\n";
    FOR(i, 0, sz(vs)) {
        cout << makepara(vs[i]) << " \n"[i == sz(vs) - 1];
    }
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