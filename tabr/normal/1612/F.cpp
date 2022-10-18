#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sw = 0;
    if (n > m) {
        sw = 1;
        swap(n, m);
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    int ans = 0;
    int q;
    cin >> q;
    set<pair<int, int>> st;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (sw) {
            swap(x, y);
        }
        st.emplace(x, y);
    }
    while (dp[n] != m) {
        if (dp[n] > n * 2) {
            while (dp[n] < m) {
                ans++;
                if (st.count(make_pair(n, dp[n]))) {
                    dp[n] += n + 1;
                } else {
                    dp[n] += n;
                }
            }
            break;
        }
        ans++;
        vector<int> new_dp(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!dp[i]) {
                continue;
            }
            int j = dp[i];
            int k = i + j;
            if (st.count(make_pair(i, j))) {
                k++;
            }
            new_dp[min(n, k)] = max(new_dp[min(n, k)], j);
            new_dp[i] = max(new_dp[i], min(m, k));
        }
        swap(dp, new_dp);
    }
    cout << ans << '\n';
    return 0;
}