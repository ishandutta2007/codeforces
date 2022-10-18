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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = 5001;
    vector<vector<int>> dp(1 << (32 - __builtin_clz(m)), vector<int>(m));
    vector<vector<int>> e(1 << (32 - __builtin_clz(m)), vector<int>(m));
    vector<vector<int>> c(m + 1);
    for (int i = 1; i < m; i++) {
        e[0][i] = 1;
        c[i].emplace_back(0);
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j : c[a[i]]) {
            dp[j ^ a[i]][a[i]] = e[j][a[i]] = 1;
            for (int k = a[i] + 1; k < m; k++) {
                if (e[j ^ a[i]][k]) {
                    break;
                }
                e[j ^ a[i]][k] = 1;
                c[k].emplace_back(j ^ a[i]);
            }
        }
        c[a[i]].clear();
    }
    vector<int> ans;
    for (int i = 0; i < (int) dp.size(); i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j]) {
                ans.emplace_back(i);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}