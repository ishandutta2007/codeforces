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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        Vi a(n);
        each(k, a) cin >> k;
        sort(all(a), greater<int>());

        vector<ll> pref = {0};
        each(k, a) pref.pb(pref.back()+k);

        while (q--) {
            ll x; cin >> x;
            int ans = int(lower_bound(all(pref), x) - pref.begin());
            if (ans == sz(pref)) ans = -1;
            cout << ans << '\n';
        }
    }
}