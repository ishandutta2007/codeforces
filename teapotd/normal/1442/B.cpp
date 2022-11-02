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
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

void solve() {
    int n, k; cin >> n >> k;
    Vi a(n), b(k);

    each(j, a) {
        cin >> j;
        j--;
    }

    each(j, b) {
        cin >> j;
        j--;
    }

    Vi prv(n), nxt(n);
    rep(i, 0, n) {
        prv[i] = i-1;
        nxt[i] = i+1;
    }

    auto del = [&](int j) {
        if (prv[j] != -1) nxt[prv[j]] = nxt[j];
        if (nxt[j] != n) prv[nxt[j]] = prv[j];
    };

    Vi invA(n);
    rep(i, 0, n) invA[a[i]] = i;

    vector<bool> used(n);
    each(j, b) used[invA[j]] = 1;
    Zp ans = 1;

    each(p, b) {
        int j = invA[p];
        int opts = (prv[j] != -1 && !used[prv[j]]);
        opts += (nxt[j] != n && !used[nxt[j]]);
        ans *= opts;
        if (opts == 0) break;

        used[j] = 0;

        if (prv[j] != -1 && !used[prv[j]]) {
            del(prv[j]);
        } else {
            assert(nxt[j] != n && !used[nxt[j]]);
            del(nxt[j]);
        }
    }

    cout << ans.x << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}