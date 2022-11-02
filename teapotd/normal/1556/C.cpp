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
    ll ans = 0;

    for (int begin = 0; begin < n; begin += 2) {
        ll pref = 0, low = 0;
        for (int end = begin+1; end < n; end += 2) {
            ll minOpen = max(-low, -pref);
            ll maxOpen = min(elems[begin], elems[end]-pref);
            ans += max(maxOpen-minOpen+1, 0ll);
            deb(begin, end, minOpen, maxOpen, low, pref);
            pref -= elems[end];
            low = min(low, pref);
            if (end+1 < n) pref += elems[end+1];
        }
        ans -= (begin+1 < n);
    }

    cout << ans << '\n';
}