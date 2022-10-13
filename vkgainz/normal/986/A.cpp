#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, s; cin >> n >> m >> k >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i], --a[i];
    vector<vector<int>> dp(n, vector<int>(k, 100000000));
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < k; i++) {
        queue<int> q;
        for(int j = 0; j < n; j++) 
            if(a[j] == i)
                dp[j][i] = 0, q.push(j);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(int next : adj[curr]) {
                if(dp[curr][i] + 1 < dp[next][i])
                    q.push(next), dp[next][i] = dp[curr][i] + 1;
            }
        }
    }

    for(int j = 0; j < n; j++) {
        sort(dp[j].begin(), dp[j].end());
        int ans = 0;
        for(int x = 0; x < s; x++)
            ans += dp[j][x];
        cout << ans << " ";
    }
    cout << "\n";
}