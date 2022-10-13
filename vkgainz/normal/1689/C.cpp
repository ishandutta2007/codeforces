#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

vector<int> dp;
vector<vector<int>> adj;
int dfs(int curr, int par) {
    int sz = 1;
    int num = 0;
    for (int next : adj[curr]) {
        if (next == par) continue;
        sz += dfs(next, curr);
        ++num;
    }
    dp[curr] = sz;
    for (int next : adj[curr]) {
        if (next == par) continue;
        if (num == 1) {
            dp[curr] = min(dp[curr], 2);
        } else {
            dp[curr] = min(dp[curr], 1 + 1 + dp[next]);
        }
    }
    
    return sz;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adj.clear(); adj.resize(n);
        dp.clear(); dp.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        cout << n - dp[0] << "\n";
    }
}