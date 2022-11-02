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

using vec2 = pair<ll, ll>;

void norm(vector<vec2>& poly) {
    vec2 low = poly[0];
    each(p, poly) low = min(low, p);
    each(p, poly) {
        p.x -= low.x;
        p.y -= low.y;
    }
    rep(i, 0, sz(poly)) {
        auto p = poly[i];
        if (p.x == 0 && p.y == 0) {
            rotate(poly.begin(), poly.begin()+i, poly.end());
        }
    }
}

void run() {
    int n; cin >> n;
    vector<vec2> poly(n), poly2(n);

    rep(i, 0, n) {
        ll x, y; cin >> x >> y;
        poly[i] = {x, y};
        poly2[i] = {-x, -y};
    }

    norm(poly);
    norm(poly2);
    deb(poly, poly2);

    bool ok = 1;

    rep(i, 0, sz(poly)) {
        if (poly[i] != poly2[i]) {
            ok = 0;
            break;
        }
    }

    cout << (ok ? "YES\n" : "nO\n");
}