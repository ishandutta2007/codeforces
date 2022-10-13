#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<array<int, 2>> dp;

void dfs(int curr, int par) {
    int s = 0;
    vector<int> in;
    for(int next : adj[curr]) {
        if(next == par) continue;
        dfs(next, curr);
        s += dp[next][1];
        in.push_back(dp[next][0] - dp[next][1]);
    }
    sort(in.begin(), in.end());
    if((int) in.size() >= 1) {
        dp[curr][0] = s + max(in.back() + 1, 0);
    }
    if((int) in.size() >= 2) {
        dp[curr][1] = s + max(2 + in.back() + in[in.size() - 2], 0);
    }
    dp[curr][1] = max(dp[curr][1], dp[curr][0]);
}

int main() {
    int n, x, y; cin >> n >> x >> y;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp.resize(n);
    dfs(0, -1);
    if(x <= y) {
        cout << dp[0][1] * 1LL * x + (n - 1 - dp[0][1]) * 1LL * y << "\n";
    }
    else {
        int r = 0;
        for(int i = 0; i < n; i++) {
            r = max(r, (int) adj[i].size());
        }
        if(r == n - 1) {
            cout << (n - 2)  * 1LL * y + x << "\n";
        }
        else cout << (n - 1) * 1LL * y << "\n";
    }
}