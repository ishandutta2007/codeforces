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

void run() {
    int k, A, h;
    cin >> k >> A >> h;

    vector<Zp> ap(100, 1);
    rep(i, 1, sz(ap)) ap[i] = ap[i-1] * A;

    int teams = 1<<k;
    int half = teams/2, plays = 1 << (half-1);

    map<ll, Vi> low[2], high[2];

    auto add = [&](map<ll, Vi>& dst, Vi& score, int ind) {
        Zp hash = 0;
        rep(i, 0, half) {
            hash += Zp(ind+i) * ap[score[i]];
        }
        dst[hash.x] = score;
    };

    rep(mask, 0, plays) {
        Vi score(half), kek(half);
        iota(all(kek), 0);
        int tmp = mask;

        while (sz(kek) > 1) {
            for (int i = 0; i < sz(kek); i += 2) {
                int won = kek[i], lost = kek[i+1];
                if (tmp & 1) swap(won, lost);
                tmp >>= 1;
                kek[i/2] = won;
                score[lost] = sz(kek) + 1;
            }
            kek.resize(sz(kek)/2);
        }

        score[kek[0]] = 1;
        add(low[0], score, 1);
        add(high[0], score, 1+half);
        score[kek[0]] = 2;
        add(low[1], score, 1);
        add(high[1], score, 1+half);
    }

    deb(low, high);

    rep(t, 0, 2) {
        each(a, low[t]) {
            Zp wanted = Zp(h) - Zp(a.x);
            if (high[!t].count(wanted.x)) {
                auto b = high[!t][wanted.x];
                each(e, a.y) cout << e << ' ';
                each(e, b) cout << e << ' ';
                cout << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
}