#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> dp(n, {{-1, 0}});
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        int cur = 1;
        if (auto iter = dp[u].lower_bound(w); iter != begin(dp[u])) cur += prev(iter)->second;
        if (dp[v][w] >= cur) continue;
        dp[v][w] = cur;
        auto iter = dp[v].find(w);
        if (iter != begin(dp[v]) && prev(iter)->second >= cur) {
            dp[v].erase(iter);
        }
        else {
            ++iter;
            while (iter != end(dp[v]) && iter->second <= cur) iter = dp[v].erase(iter);
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    exit(0);
}