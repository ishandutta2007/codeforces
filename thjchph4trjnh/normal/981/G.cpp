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
const int MOD = 998244353;
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

const int maxn = 2e5 + 5;
int n, q;
set<pi> heap[maxn];

int st[maxn << 2];
int lz[maxn << 2][2];

void pushdown(int p, int L, int R) {
    if (lz[p][1] != 1) {
        st[p] = mult(st[p], lz[p][1]);
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i][0] = mult(lz[p << 1 | i][0], lz[p][1]);
                lz[p << 1 | i][1] = mult(lz[p << 1 | i][1], lz[p][1]);
            }
        }
        lz[p][1] = 1;
    }
    if (lz[p][0]) {
        addmod(st[p], mult(lz[p][0], R - L + 1));
        if (L < R) {
            FOR(i, 0, 2) {
                addmod(lz[p << 1 | i][0], lz[p][0]);
            }
        }
        lz[p][0] = 0;
    }
}
void upd0(int p, int l, int r, int L, int R, int val) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        lz[p][0] = val;
        pushdown(p, L, R);
        return;
    }
    upd0(p << 1, l, r, L, L + R >> 1, val);
    upd0(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1];
    addmod(st[p], st[p << 1 | 1]);
}
void upd1(int p, int l, int r, int L, int R, int val) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        lz[p][1] = val;
        pushdown(p, L, R);
        return;
    }
    upd1(p << 1, l, r, L, L + R >> 1, val);
    upd1(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1];
    addmod(st[p], st[p << 1 | 1]);
}
int query(int p, int l, int r, int L, int R) {
    pushdown(p, L, R);
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) return st[p];
    int res = query(p << 1, l, r, L, L + R >> 1);
    addmod(res, query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    return res;
}

void upd(int l, int r, int x) {
    if (!sz(heap[x])) {
        heap[x].insert(mp(l, r));
        upd0(1, l, r, 0, n - 1, 1);
        return;
    }
    auto it = heap[x].upper_bound(mp(l, INF));
    auto insect = [&] (int x1, int y1, int x2, int y2) {
        if (y1 < x2) return 0;
        if (y2 < x1) return 0;
        return 1;
    };
    int u = l, v = r, t = l - 1;
    vii rems;
    if (it != heap[x].begin()) {
        it--;
        if (insect(l, r, it->fi, it->se + 1)) {
            int p = max(l, it->fi);
            int q = min(r, it->se);
            if (p <= q) {
                upd1(1, p, q, 0, n - 1, 2);
                t = q;
            }
            u = it->fi;
            chkmax(v, it->se);
            rems.pb(*it);
        }
        it++;
    }
    if (it != heap[x].end()) {
        for (auto it2 = it; it2 != heap[x].end() && insect(l, r + 1, it2->fi, it2->se); it2++) {
            if (t + 1 <= min(r, it2->fi - 1)) {
                upd0(1, t + 1, min(r, it2->fi - 1), 0, n - 1, 1);
            }
            int p = max(l, it2->fi);
            int q = min(r, it2->se);
            if (p <= q) {
                upd1(1, p, q, 0, n - 1, 2);
            }
            chkmax(v, it2->se);
            chkmax(t, it2->se);
            rems.pb(*it2);
        }
        if (t + 1 <= r) {
            upd0(1, t + 1, r, 0, n - 1, 1);
        }
    }
    else {
        if (t + 1 <= r) {
            upd0(1, t + 1, r, 0, n - 1, 1);
        }
    }
    for (auto it : rems) {
        heap[x].erase(it);
    }
    heap[x].insert(mp(u, v));
}

void thjchph4trjnh() {
    FOR(i, 0, maxn << 2) lz[i][0] = 0, lz[i][1] = 1;
    cin >> n >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--, x--;
            upd(l, r, x);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            cout << query(1, l, r, 0, n - 1) << "\n";
        }
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
    thjchph4trjnh();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}