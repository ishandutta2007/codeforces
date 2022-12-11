#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 7;
vector <int> g[MAX_N];
int sz[MAX_N];
int dp[MAX_N];

void dfs(int v, int prev = -1) {
    sz[v] = 1;
    if (g[v].size() == 1 && prev != -1) {
        dp[v] = 0;
        return;
    }
    dp[v] = 0;
    for (int u : g[v]) {
        if (u == prev) continue;
        dfs(u, v);
        sz[v] += sz[u];
        if (sz[u] % 2 == 0) dp[v] += dp[u] + 1;
        else dp[v] += dp[u];
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v, u;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    dfs(1);
    cout << dp[1] << endl;
    return 0;
}