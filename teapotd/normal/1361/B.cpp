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

constexpr int MOD = 1000000007;

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
    int t; cin >> t;

    while (t--) {
        int n, p; cin >> n >> p;
        Vi elems(n);
        each(e, elems) cin >> e;

        if (p == 1) {
            cout << n%2 << '\n';
            continue;
        }

        sort(all(elems));
        reverse(all(elems));

        ll diff = 1, pos = elems[0];
        bool kek = 0;
        int xd;

        rep(i, 1, sz(elems)) {
            while (diff > 0 && pos > elems[i]) {
                diff *= p;
                pos--;
                if (diff > int(1e7)) {
                    kek = 1;
                    xd = i;
                    break;
                }
            }
            if (kek) break;
            pos = elems[i];
            diff = abs(diff - 1);
        }

        Zp ans = Zp(p).pow(pos) * diff;

        if (kek) {
            rep(j, xd, sz(elems)) {
                ans -= Zp(p).pow(elems[j]);
            }
        }

        cout << ans.x << '\n';
    }
}