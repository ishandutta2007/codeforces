#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long inf = 1e15;
vector<pair<int, int>> g[maxn];
int w[maxn];
long long dp[maxn];

long long dfs(int x, int p) {
    long long res = 0;
    vector<long long> c;
    dp[x] = w[x];
    long long a = -inf, b = -inf;
    for (const auto &e : g[x]) {
        int u = e.first, d = e.second;
        if (u == p) continue;
        res = max(res, dfs(u, x));
        if (dp[u] - d > a) b = a, a = dp[u] - d;
        else if (dp[u] - d > b) b = dp[u] - d;
    }
    dp[x] = max(dp[x], w[x] + a);
    res = max(res, a + b + w[x]);
    res = max(res, dp[x]);
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, d; scanf("%d%d%d", &x, &y, &d);
        --x, --y;
        g[x].emplace_back(y, d);
        g[y].emplace_back(x, d);
    }
    printf("%lld\n", dfs(0, -1));
}