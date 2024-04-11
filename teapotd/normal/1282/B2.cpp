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
    int t; cin >> t;

    while (t--) {
        int n, p, k; cin >> n >> p >> k;
        Vi elems(n);
        each(e, elems) cin >> e;
        sort(all(elems));

        vector<ll> dp(n+1);
        int ans = 0;

        rep(i, 1, n+1) {
            dp[i] = dp[i-1] + elems[i-1];
            if (i >= k) {
                dp[i] = min(dp[i], dp[i-k] + elems[i-1]);
            }
            if (dp[i] <= p) {
                ans = i;
            }
        }

        cout << ans << '\n';
    }
}