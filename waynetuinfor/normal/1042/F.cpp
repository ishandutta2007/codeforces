#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int n, k, dp[maxn];

int dfs(int x, int p) {
    int res = 0;
    vector<int> d;
    for (int u : g[x]) {
        if (u == p) continue;
        res += dfs(u, x);
        d.push_back(dp[u] + 1);
    }
    sort(d.begin(), d.end());
    while (d.size() >= 2 && d[d.size() - 1] + d[d.size() - 2] > k) ++res, d.pop_back();
    if (d.size()) dp[x] = d.back();
    return res;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) continue;
        printf("%d\n", dfs(i, -1) + 1);
        return 0;
    }
    __builtin_unreachable();
}