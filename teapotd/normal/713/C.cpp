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

ll dp[3005][3005]; // prefix, upper bound

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi vals;

    rep(i, 0, n) {
        elems[i] -= i;
        vals.pb(elems[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    rep(pref, 1, n+1) {
        rep(up, 0, sz(vals)) {
            dp[pref][up] = dp[pref-1][up] + abs(elems[pref-1] - vals[up]);
            if (up > 0) {
                dp[pref][up] = min(dp[pref][up], dp[pref][up-1]);
            }
        }
    }

    cout << dp[n][sz(vals)-1] << endl;
}