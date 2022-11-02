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

void answer(Zp n) {
    cout << n.x << endl;
    exit(0);
}

void run() {
    string s; cin >> s;

    int ones = int(count(all(s), '1'));
    if (ones == 0 || ones == sz(s)) {
        answer(sz(s));
    }

    int prefZero = 0, sufZero = 0;
    while (s[prefZero] == '0') prefZero++;
    while (s.back() == '0') {
        sufZero++;
        s.pop_back();
    }

    Zp ans = Zp(prefZero+1) * Zp(sufZero+1);
    s = s.substr(prefZero);

    vector<Pii> segs; // number of ones, number of zeroes
    int pos = 0;

    while (pos < sz(s)) {
        int begin = pos;
        while (pos < sz(s) && s[pos] == '1') pos++;
        int mid = pos;
        while (pos < sz(s) && s[pos] == '0') pos++;
        segs.pb({ mid-begin, pos-mid });
    }

    vector<Zp> dp(sz(segs));
    dp.back() = segs.back().x;

    vector<pair<int, Zp>> que; // index of segment, ways to choose

    for (int i = sz(segs)-2; i >= 0; i--) {
        while (!que.empty() && segs[que.back().x].y <= segs[i].y) {
            que.pop_back();
        }

        if (que.empty()) {
            que.pb({ i, Zp(segs[i].y) * dp[i+1] });
        } else {
            auto p = que.back();
            que.pb({ i, Zp(segs[i].y) * (dp[i+1] - dp[p.x+1]) + p.y });
        }

        dp[i] = dp[i+1] + Zp(segs[i].x) * (que.back().y+1);
    }

    ans *= dp[0];
    answer(ans);
}