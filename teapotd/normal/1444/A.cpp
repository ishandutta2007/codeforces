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

using Pll = pair<ll, ll>;

vector<Pll> factorize(ll n) {
    vector<Pll> ret;

    for (ll d = 2; d*d <= n; d++) {
        if (n%d == 0) {
            ret.pb({d, 0});
            while (n%d == 0) {
                ret.back().y++;
                n /= d;
            }
        }
    }

    if (n > 1) {
        ret.pb({n, 1});
    }

    return ret;
}

ll solve() {
    ll p, q; cin >> p >> q;

    if (p%q != 0) {
        return p;
    }

    ll ans = 0;

    each(f, factorize(q)) {
        ll alt = p;
        while (alt%q == 0 && alt%f.x == 0) {
            alt /= f.x;
        }
        if (alt%q != 0) {
            ans = max(ans, alt);
        }
    }

    return ans;
}

void run() {
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}