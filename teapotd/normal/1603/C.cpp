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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

constexpr int MOD = 998244353;

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
    Zp operator-() const { return Zp(0)-*this; }
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

void solve() {
    int n; cin >> n;
    vector<ll> elems(n);
    each(e, elems) cin >> e;

    vector<ll> divs(n, 1);
    Zp ans = 0, cur = 0;

    rep(i, 0, n) {
        for (int j = i-1; j >= 0; j--) {
            ll last = elems[j+1] / divs[j+1];
            ll d = (elems[j]+last-1) / last;
            assert(d >= divs[j]);
            if (d == divs[j]) break;
            cur -= Zp(divs[j]-1)*(j+1);
            divs[j] = d;
            cur += Zp(divs[j]-1)*(j+1);
        }
        ans += cur;
    }

    cout << ans.x << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}