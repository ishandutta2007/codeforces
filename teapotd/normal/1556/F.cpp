#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

constexpr int MOD = 1e9+7;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

void run() {
    int n; cin >> n;
    Vi a(n);
    each(e, a) cin >> e;

    vector<vector<Zp>> pEdge(n, vector<Zp>(n));
    vector<vector<Zp>> pEdgeInv(n, vector<Zp>(n));

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i != j) {
                pEdge[i][j] = Zp(a[j]) / (a[i]+a[j]);
                pEdgeInv[i][j] = pEdge[i][j].inv();
            }
        }
    }

    vector<Zp> pStrong(1 << n), pDir(1 << n);
    pStrong[0] = 1;
    Zp ans = 0;

    rep(s, 1, 1<<n) {
        pStrong[s] = 1;
        pDir[s] = 1;

        for (int t = (s-1) & s; t; t = (t-1) & s) {
            int rest = t^s;
            int del = __builtin_ctz(rest);
            pDir[t] = pDir[t ^ (1<<del)];

            rep(i, 0, n) if (i != del && ((s >> i) & 1)) {
                if ((t >> i) & 1) {
                    pDir[t] *= pEdge[del][i];
                } else {
                    pDir[t] *= pEdgeInv[i][del];
                }
            }

            pStrong[s] -= pStrong[t] * pDir[t];
        }
    }

    rep(s, 1, 1<<n) {
        ans += pStrong[s] * pDir[s] * __builtin_popcount(s);
    }

    deb(pStrong, pDir);
    deb(pEdge, pEdgeInv);
    deb(a);

    cout << ans.x << '\n';
}