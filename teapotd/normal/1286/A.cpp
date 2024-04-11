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

int dp[105][105][105][2]; // pref, zeroes, ones, last

void run() {
    int n; cin >> n;
    Vi perm(n);
    each(e, perm) cin >> e;

    int cnt[2] = {};
    rep(i, 1, n+1) cnt[i%2]++;
    each(e, perm) if (e) cnt[e%2]--;

    rep(pref, 1, n+1) rep(zeroes, 0, n+1) rep(ones, 0, n+1) rep(last, 0, 2) {
        dp[pref][zeroes][ones][last] = 1e6;
        if (perm[pref-1] != 0) {
            if (perm[pref-1]%2 == last) {
                dp[pref][zeroes][ones][last] = min(dp[pref-1][zeroes][ones][0] + last, dp[pref-1][zeroes][ones][1] + !last);
            }
            continue;
        }

        int z = zeroes - (last == 0);
        int o = ones - (last == 1);

        if (z >= 0 && o >= 0) {
            dp[pref][zeroes][ones][last] = dp[pref-1][z][o][last];
            dp[pref][zeroes][ones][last] = min(dp[pref][zeroes][ones][last], dp[pref-1][z][o][!last]+1);
        }
    }

    int ans = min(dp[n][cnt[0]][cnt[1]][0], dp[n][cnt[0]][cnt[1]][1]);
    cout << ans << endl;
}