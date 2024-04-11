#include <bits/stdc++.h>
using namespace std;

long long dp[201][201];
long long MOD = 1e9 + 7;
long long inv = (MOD + 1) / 2;
long long get_inv(long long b, long long p = MOD - 2) {
    if(p == 0) return 1LL;
    long long x = get_inv(b, p / 2);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}
vector<int> depth;
int tab[201][8];

int lca(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    for(int b = 7; b >= 0; b--)
        if(depth[u] - (1 << b) >= depth[v])
            u = tab[u][b];
    if(u == v) return u;
    for(int b = 7; b >= 0; b--)
        if(tab[u][b] != tab[v][b])
            u = tab[u][b], v = tab[v][b];
    return tab[u][0];
}

vector<vector<int>> adj;

void dfs(int curr, int par) {
    for(int next : adj[curr]) {
        if(next == par) continue;
        tab[next][0] = curr;
        depth[next] = depth[curr] + 1;
        dfs(next, curr);
    }
}

int main() {
    for(int i = 0; i <= 200; i++) {
        dp[0][i] = 1;
        dp[i][0] = 0;
    }
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= 200; j++) {
            dp[i][j] = inv * 1LL * dp[i - 1][j] + inv * 1LL * dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    int n; cin >> n;
    depth.resize(n);
    adj.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans = 0LL;
    for(int i = 0; i < n; i++) {
        tab[i][0] = i;
        depth[i] = 0;
        dfs(i, -1);
        for(int j = 1; j < 8; j++)
            for(int k = 0; k < n; k++)
                tab[k][j] = tab[ tab[k][j - 1] ][j - 1];
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                //p[k before j]
                int l = lca(k, j);
                int x = depth[k] - depth[l], y = depth[j] - depth[l];
                ans += dp[x][y];
            }
            ans %= MOD;
        }
    }
    ans *= get_inv(n);
    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}