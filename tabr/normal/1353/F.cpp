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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        vector<ll> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] - i - j <= a[0][0]) {
                    st.emplace_back(a[i][j] - i - j);
                }
            }
        }
        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());
        ll ans = 1e18;
        for (ll k : st) {
            vector<vector<ll>> dp(n, vector<ll>(m, 1e18));
            dp[0][0] = a[0][0] - k;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int ps = i + j;
                    if (i != 0 && a[i][j] - k - ps >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - k - ps);
                    }
                    if (j != 0 && a[i][j] - k - ps >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - k - ps);
                    }
                }
            }
            ans = min(ans, dp[n - 1][m - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}