#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> E(N);
        vector<int> k(N);
        for (int u = 0; u < N; ++u) {
            cin >> k[u];
            for (int j = 0; j < k[u]; ++j) {
                int v;
                cin >> v;
                --v;
                E[v].push_back(u);
            }
        }
        queue<int> q;
        for (int u = 0; u < N; ++u) {
            if (k[u] == 0) {
                q.push(u);
            }
        }
        vector<int> V;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            V.push_back(u);
            for (auto v : E[u]) {
                if (--k[v] == 0) {
                    q.push(v);
                }
            }
        }
        if ((int)V.size() < N) {
            cout << "-1\n";
            continue;
        }
        vector<int> dp(N);
        for (auto u : V) {
            for (auto v : E[u]) {
                dp[v] = max(dp[v], dp[u] + (u > v ? 1 : 0));
            }
        }
        int ans = *max_element(dp.begin(), dp.end()) + 1;
        cout << ans << '\n';
    }
    exit(0);
}