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

void translate(vector<Pll>& elems, ll dx, ll dy) {
    each(e, elems) {
        e.x += dx;
        e.y += dy;
    }
}

void scaleUp(vector<Pll>& elems, ll d) {
    each(e, elems) {
        e.x *= d;
        e.y *= d;
    }
}

void scaleDown(vector<Pll>& elems, ll d) {
    each(e, elems) {
        e.x /= d;
        e.y /= d;
    }
}

void rot90(vector<Pll>& elems) {
    each(e, elems) {
        ll a = e.x+e.y, b = e.x-e.y;
        e = {a, b};
    }
}

Vi pick(vector<Pll>& elems) {
    Vi ret;
    rep(i, 0, sz(elems)) {
        Pll e = elems[i];
        if ((e.x+e.y) % 2) {
            ret.pb(i);
        }
    }
    return ret;
}

void run() {
    int n; cin >> n;
    vector<Pll> elems(n);
    each(e, elems) cin >> e.x >> e.y;

    while (true) {
        ll minX = 0, minY = 0;
        each(e, elems) {
            minX = min(minX, e.x);
            minY = min(minY, e.y);
        }

        translate(elems, -minX, -minY);
        deb(elems);

        Vi odd = pick(elems);

        if (sz(odd) >= 1 && sz(odd) < n) {
            cout << sz(odd) << '\n';
            each(e, odd) cout << e+1 << ' ';
            cout << '\n';
            return;
        }

        if (!odd.empty()) {
            translate(elems, 1, 0);
            continue;
        }

        bool allEven = 1;
        each(e, elems) {
            if (e.x%2 || e.y%2) {
                allEven = 0;
            }
        }

        if (allEven) {
            scaleDown(elems, 2);
            continue;
        }

        rot90(elems);
    }
}