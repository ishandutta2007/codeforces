#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1'000'000'000 + 7;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<pair<int, int>>> g(n);

    auto AddEdge = [&](int u, int v, int w) {
        vector<int> dg;
        while (w > 0) {
            dg.push_back(w % 10);
            w /= 10;
        }
        reverse(dg.begin(), dg.end());
        for (int i = 0; i < dg.size(); ++i) {
            if (i + 1 == dg.size()) {
                g[u].emplace_back(v, dg[i]);
                continue;
            }
            int nxt = g.size();
            g.emplace_back();
            g[u].emplace_back(nxt, dg[i]);
            u = nxt;
        }
    };

    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        AddEdge(u, v, i + 1);
        AddEdge(v, u, i + 1);
    }
    int s = g.size();
    vector<int> dp(s, -1), ans(s, -1), id(s, -1);
    vector<pair<int, int>> fr(s, make_pair(-1, -1));
    vector<int> que;
    que.push_back(0);
    fr[0] = make_pair(0, 0);
    ans[0] = 0;
    dp[0] = 0;
    id[0] = 0;
    while (!que.empty()) {
        vector<int> nque;
        for (int x : que) {
            for (auto e : g[x]) {
                int u = e.first, w = e.second;
                if (dp[u] == -1 || dp[u] == dp[x] + 1 && make_pair(id[x], w) < fr[u]) {
                    fr[u] = make_pair(id[x], w);
                    ans[u] = (10LL * ans[x] + w) % kMod;
                    if (dp[u] == -1) {
                        dp[u] = dp[x] + 1;
                        nque.push_back(u);
                    }
                }
            }
        }
        sort(nque.begin(), nque.end(), [&](int u, int v) { return fr[u] < fr[v]; });
        for (int i = 0, j = 0, z = 0; i < nque.size(); i = j) {
            for (j = i; j < nque.size() && fr[nque[i]] == fr[nque[j]]; ++j) id[nque[j]] = z;
            z++;
        }
        nque.swap(que);
    }

    for (int i = 1; i < n; ++i) printf("%d\n", ans[i]);
    return 0;
}