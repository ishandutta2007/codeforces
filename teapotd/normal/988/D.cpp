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

    auto has = [&](ll e) {
        auto it = lower_bound(all(elems), e);
        return it != elems.end() && *it == e;
    };

    vector<ll> ans;

    for (ll p = 1; p < ll(2e9); p *= 2) {
        rep(i, 0, n) {
            ll e1 = elems[i];
            ll e2 = elems[i]+p;
            ll e3 = elems[i]+p*2;

            if (sz(ans) < 3 && has(e2) && has(e3)) {
                ans = {e1, e2, e3};
            } else if (sz(ans) < 2 && has(e2)) {
                ans = {e1, e2};
            } else if (ans.empty()) {
                ans = {e1};
            }
        }
    }

    cout << sz(ans) << '\n';
    each(a, ans) cout << a << ' ';
    cout << '\n';
}