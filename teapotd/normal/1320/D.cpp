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

constexpr ll MOD1 = 2000000011;
constexpr ll MOD2 = 2000000033;
constexpr ll MOD3 = 2000000087;
constexpr ll MOD4 = 2000000089;
constexpr ll BASE = 3;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

ll modInv(ll a, ll m) {
    if (a == 1) return 1;
    return ((a - modInv(m%a, a))*m + 1) / a;
}

struct Hasher {
    vector<ll> h1, h2, h3, h4;
    ll inv1, inv2, inv3, inv4;

    Hasher(Vi& elems) {
        ll mult1 = 1, mult2 = 1, mult3 = 1, mult4 = 1;
        h1.pb(0); h2.pb(0); h3.pb(0); h4.pb(0);
        each(e, elems) {
            h1.pb((h1.back() + (e+1)*mult1) % MOD1);
            h2.pb((h2.back() + (e+1)*mult2) % MOD2);
            h3.pb((h3.back() + (e+1)*mult3) % MOD3);
            h4.pb((h4.back() + (e+1)*mult4) % MOD4);
            mult1 = mult1*BASE % MOD1;
            mult2 = mult2*BASE % MOD2;
            mult3 = mult3*BASE % MOD3;
            mult4 = mult4*BASE % MOD4;
        }
        inv1 = modInv(BASE, MOD1);
        inv2 = modInv(BASE, MOD2);
        inv3 = modInv(BASE, MOD3);
        inv4 = modInv(BASE, MOD4);
    }

    pair<pair<ll, ll>, pair<ll, ll>> get(int b, int e) {
        ll a1 = (h1[e] - h1[b]) * modPow(inv1, b, MOD1) % MOD1;
        ll a2 = (h2[e] - h2[b]) * modPow(inv2, b, MOD2) % MOD2;
        ll a3 = (h3[e] - h3[b]) * modPow(inv3, b, MOD3) % MOD3;
        ll a4 = (h4[e] - h4[b]) * modPow(inv4, b, MOD4) % MOD4;
        if (a1 < 0) a1 += MOD1;
        if (a2 < 0) a2 += MOD2;
        if (a3 < 0) a3 += MOD3;
        if (a4 < 0) a4 += MOD4;
        return {{a1,a2},{a3,a4}};
    }
};

void run() {
    int n; cin >> n;
    string s; cin >> s;

    Vi ones = {0};
    each(c, s) ones.pb(ones.back() + (c == '1'));

    Vi left(n), right(n), par;
    int lastZero = -1;

    rep(i, 0, n) {
        if (s[i] == '0') {
            lastZero = sz(par);
            par.pb(ones[i] % 2);
        }
        left[i] = lastZero;
    }

    lastZero = sz(par);
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') lastZero--;
        right[i] = lastZero;
    }

    Vi neg = par;
    each(k, neg) k ^= 1;

    Hasher hPar(par), hNeg(neg);

    auto getHash = [&](int b, int e) {
        auto& hasher = (ones[b] % 2 ? hNeg : hPar);
        int l = right[b], r = left[e-1];
        assert(l <= r);
        return hasher.get(l, r+1);
    };

    int q; cin >> q;

    while (q--) {
        int begin1, begin2, len;
        cin >> begin1 >> begin2 >> len;

        begin1--; begin2--;
        int end1 = begin1+len, end2 = begin2+len;

        bool ok = 1;

        if (ones[end1]-ones[begin1] != ones[end2]-ones[begin2]) {
            ok = 0;
        } else if (ones[end1]-ones[begin1] != 0 && ones[end1]-ones[begin1] != len) {
            ok = getHash(begin1, end1) == getHash(begin2, end2);
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}