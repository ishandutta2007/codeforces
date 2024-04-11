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
    int n;
    ll m;
    cin >> n >> m;

    vector<pair<int, Pii>> events(n);

    each(e, events) {
        cin >> e.x >> e.y.x >> e.y.y;
    }

    sort(all(events));

    ll t = 0, lo = m, hi = m;

    each(e, events) {
        lo -= e.x-t;
        hi += e.x-t;
        t = e.x;

        lo = max(lo, ll(e.y.x));
        hi = min(hi, ll(e.y.y));

        if (lo > hi) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}