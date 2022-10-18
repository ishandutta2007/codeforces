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
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int g, r;
    cin >> g >> r;
    vector<vector<int>> dp(m, vector<int>(g, 1e9));
    vector<vector<bool>> ok(m, vector<bool>(g));
    dp[0][0] = 0;
    ok[0][0] = true;
    deque<pair<int, int>> deq;
    deq.emplace_back(0, 0);
    while (deq.size()) {
        pair<int, int> p = deq.front();
        deq.pop_front();
        int x = dp[p.first][p.second];
        for (int i = p.first + 1; i < min(m, p.first + 2); i++) {
            int j = p.second + d[i] - d[p.first];
            if (j > g) break;
            if (j == g) {
                if (ok[i][0]) break;
                ok[i][0] = true;
                dp[i][0] = x + 1;
                deq.emplace_back(i, 0);
                break;
            }
            if (ok[i][j]) continue;
            ok[i][j] = true;
            dp[i][j] = x;
            deq.emplace_front(i, j);
        }
        for (int i = p.first - 1; i > max(-1, p.first - 2); i--) {
            int j = p.second - d[i] + d[p.first];
            if (j > g) break;
            if (j == g) {
                if (ok[i][0]) break;
                ok[i][0] = true;
                dp[i][0] = x + 1;
                deq.emplace_back(i, 0);
                break;
            }
            if (ok[i][j]) continue;
            ok[i][j] = true;
            dp[i][j] = x;
            deq.emplace_front(i, j);
        }
    }
    ll ans = 1e18;
    if (dp[m - 1][0] != 1e9) {
        ans = (ll)dp[m - 1][0] * g + (ll)(dp[m - 1][0] - 1) * r;
    }
    for (int i = 1; i < g; i++) {
        if (dp[m - 1][i] == 1e9) continue;
        ans = min(ans, (ll)dp[m - 1][i] * (r + g) + i);
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
    return 0;
}