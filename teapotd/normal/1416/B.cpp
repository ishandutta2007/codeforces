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

void solve() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    int target = 0;
    each(e, elems) target += e;

    if (target%n != 0) {
        cout << "-1\n";
        return;
    }

    target /= n;
    vector<pair<Pii, int>> ops;

    deb(target);

    auto op = [&](int i, int j, int x) {
        if (x > 0) {
            ops.pb({{i, j}, x});
            elems[i] -= x*(i+1);
            elems[j] += x*(i+1);
        }
        deb(i+1, j+1, x, elems);
    };

    rep(i, 1, n) {
        int r = elems[i] % (i+1);
        if (r > 0) r = i+1 - r;
        op(0, i, r);
        op(i, 0, elems[i] / (i+1));
    }

    rep(i, 1, n) {
        op(0, i, target);
    }

    cout << sz(ops) << '\n';
    each(e, ops) {
        cout << e.x.x+1 << ' ' << e.x.y+1 << ' ' << e.y << '\n';
    }
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}