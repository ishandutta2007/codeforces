#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    vector<vector<ll>> s(n, vector<ll>(p + 1));
    for (int i = 0; i < n; i++) {
        cin >> s[i][0];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> s[i][j + 1];
        }
    }
    sort(s.rbegin(), s.rend());
    vector<ll> dp(1 << p);
    for (int i = 0; i < n; i++) {
        vector<ll> ndp = dp;
        for (int msk = 0; msk < (1 << p); msk++) {
            int c = __builtin_popcount(msk);
            if (c > i) {
                continue;
            }
            for (int j = 0; j < p; j++) {
                if (!(msk & (1 << j))) {
                    ndp[msk | (1 << j)] = max(ndp[msk | (1 << j)], dp[msk] + s[i][j + 1]);
                }
            }
            if (k > i - c) {
                ndp[msk] = max(ndp[msk], dp[msk] + s[i][0]);
            }
        }
        swap(ndp, dp);
    }
    cout << dp[(1 << p) - 1] << '\n';
    return 0;
}