#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) scanf("%d", &cost[i][j]);
    }
    vector<vector<vector<int>>> route(n, vector<vector<int>>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                route[i][j].push_back(k);
            }
            sort(route[i][j].begin(), route[i][j].end(), [&](int u, int v) { return cost[i][u] + cost[u][j] < cost[i][v] + cost[v][j]; });
        }
    }
    constexpr int64_t kInf = 1'000'000'000'000'000;
    vector<int> used(n), choose(k / 2);
    used[0]++;
    choose[0] = 0;

    function<int64_t(int)> Dfs = [&](int p) {
        if (p == k / 2) {
            int64_t sum = 0;
            for (int i = 0; i < k / 2; ++i) {
                int x = choose[i], y = choose[(i + 1) % (k / 2)];
                bool ok = false;
                for (int u : route[x][y]) {
                    if (!used[u]) {
                        sum += cost[x][u] + cost[u][y];
                        ok = true;
                        break;
                    }
                }
                if (!ok) return kInf;
            }
            return sum;
        }
        int64_t res = kInf;
        for (int i = 0; i < n; ++i) {
            choose[p] = i;
            used[i]++;
            res = min(res, Dfs(p + 1));
            choose[p] = -1;
            used[i]--;
        }
        return res;
    };

    printf("%lld\n", Dfs(1));
}