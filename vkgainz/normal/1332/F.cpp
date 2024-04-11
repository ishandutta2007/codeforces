#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

struct Node {
    long long val[2][2];
};

void make(Node &x) {
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            x.val[a][b] = 1LL;
}

vector<Node> dp;
long long MOD = 998244353;

inline void mult(long long &x, long long v) { x *= v, x %= MOD; }

void dfs(int curr, int par) {
    long long x = 1LL, y = 1LL, z = 1LL;
    make(dp[curr]);
    for (int next : adj[curr]) {
        if (next == par) continue;
        dfs(next, curr);
        mult(x, dp[next].val[1][1] + dp[next].val[0][1]);
        mult(y, dp[next].val[0][1] + dp[next].val[1][0]);
        mult(z, dp[next].val[0][1]);
    }
    dp[curr].val[1][1] = (x + y) % MOD;
    dp[curr].val[0][1] = (x + y - z) % MOD;
    dp[curr].val[1][0] = x;
    dp[curr].val[0][0] = x;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    dp.resize(n), adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);

    if (dp[0].val[0][1] < 0) dp[0].val[0][1] += MOD;
    cout << dp[0].val[0][1] - 1 << "\n";
}