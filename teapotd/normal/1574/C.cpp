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

void run() {
    int n; cin >> n;
    vector<ll> elems(n);
    each(e, elems) cin >> e;

    sort(all(elems));

    ll sum = 0;
    each(e, elems) sum += e;

    int m; cin >> m;

    while (m--) {
        ll x, y; cin >> x >> y;
        ll ans = INT64_MAX;

        auto it = lower_bound(all(elems), x);
        if (it != elems.begin()) it--;

        rep(i, 0, 3) if (it != elems.end()) {
            ll a = *it, b = sum - a;
            ans = min(ans, max(x-a, 0ll)+max(y-b, 0ll));
            it++;
        }

        cout << ans << '\n';
    }
}