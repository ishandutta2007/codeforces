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
    #define OP(c,d) Zp& operator c##=(Zp r) \
        { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
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
    each(k, a) cin >> k;

    a.pb(0);
    sort(all(a));
    n++;

    if (a[n-2]*2 > a[n-1]) {
        cout << 0 << '\n';
        return;
    }

    vector<Zp> fac(n+5, 1);
    rep(i, 2, sz(fac)) fac[i] = fac[i-1] * i;

    vector<Zp> dp(n);
    dp[n-1] = 1;

    for (int i = n-2; i >= 0; i--) {
        int before = 0;
        while (i-before-1 >= 0 && a[i-before-1]*2 > a[i]) {
            before++;
        }

        int cut = i;

        for (int j = i+1; j < n; j++) {
            if (a[i]*2 > a[j]) continue;
            int k = j;
            while (k+1 < n && a[k+1] == a[j]) k++;
            while (a[cut]*2 <= a[j]) cut++;

            int add = cut - i + before - 1;
            Zp alt = dp[k] * (k-j+1) * fac[n-cut-1+add] / fac[n-cut-1];
            dp[i] += alt;

            //deb(i, j, cut, add, k, before, alt);
            j = k;
        }
    }

    //deb(dp);
    cout << dp[0].x << '\n';
}