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

ll modPow(ll a, ll e, ll m) { // a^e mod m
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
    #define OP(c,d) Zp& operator c##=(Zp r) { \
            x = x d; return *this; } \
        Zp operator c(Zp r) const { \
            Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp operator-() const { Zp t; t.x = MOD-x; return t; }
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; } // For deb()
};

vector<Zp> two, invTwo;

Zp solve(int len, vector<Pii>& segs) {
    sort(all(segs), [&](Pii a, Pii b) {
        return mp(a.y, -a.x) < mp(b.y, -b.x);
    });

    int left = -1;
    vector<Pii> good;

    each(s, segs) {
        if (s.x > left) {
            left = s.x;
            good.pb(s);
        }
    }

    int n = sz(good);
    vector<Zp> dp(n);

    Zp pref = 0, whole = 0;
    int j = 0;

    rep(i, 0, n) {
        auto& s = good[i];
        dp[i] = two[len-(s.y-s.x)];

        while (j < i && good[j].y <= s.x) {
            pref -= dp[j] * invTwo[len-good[j].y];
            whole += dp[j];
            j++;
        }

        dp[i] -= whole * invTwo[s.y-s.x];
        dp[i] -= pref * two[len-s.y];

        pref += dp[i] * invTwo[len-s.y];
    }

    Zp ans = two[len];
    each(k, dp) ans -= k;
    return ans;
}

void run() {
    int n, k, m; cin >> n >> k >> m;
    vector<pair<Pii, int>> segs(m);

    each(s, segs) {
        cin >> s.x.x >> s.x.y >> s.y;
        s.x.x--;
    }

    sort(all(segs), [&](pair<Pii, int> l, pair<Pii, int> r) {
        Pii a = l.x, b = r.x;
        return mp(a.y, -a.x) < mp(b.y, -b.x);
    });

    Zp ans = 1;
    vector<Pii> zero;
    Vi must, ind;

    two.resize(n+5, 1);
    invTwo.resize(n+5, 1);

    rep(i, 1, sz(two)) {
        two[i] = two[i-1] * 2;
        invTwo[i] = two[i].inv();
    }

    rep(bit, 0, k) {
        must.assign(n+1, 0);
        zero.clear();

        each(s, segs) {
            if ((s.y >> bit) & 1) {
                must[s.x.x]++;
                must[s.x.y]--;
            }
        }

        rep(i, 1, n+1) must[i] += must[i-1];
        assert(must.back() == 0);
        must.pop_back();

        ind.resize(n);
        ind[0] = !must[0]-1;
        rep(i, 1, n) ind[i] = ind[i-1] + !must[i];

        each(s, segs) {
            if ((s.y >> bit) & 1) continue;

            int first = s.x.x, last = s.x.y-1;
            first = ind[first] + !!must[first];
            last = ind[last];

            if (first <= last) {
                zero.pb({first, last+1});
            } else {
                cout << 0 << '\n';
                return;
            }
        }

        ans *= solve(ind.back()+1, zero);
    }

    cout << ans.x << '\n';
}