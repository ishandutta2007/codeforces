#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n);

    constexpr int kMod = 1'000'000'000 + 7;

    auto Count = [&](const vector<pair<long long, int>> &gd, int d) {
        int res = 0;
        for (int i = 0; i < gd.size(); ++i) {
            int l = gd[i].second, r = i + 1 < gd.size() ? gd[i + 1].second - 1 : d, gk = gd[i].first % kMod;
            res += 1LL * (r - l + 1) * gk % kMod;
            if (res >= kMod) res -= kMod;
        }
        return res;
    };

    function<int(int, int, vector<pair<long long, int>>)> Dfs = [&](int x, int p, vector<pair<long long, int>> gd) {
        dep[x] = ~p ? dep[p] + 1 : 0;
        for (auto &u : gd) u.first = __gcd(u.first, a[x]);
        gd.emplace_back(a[x], dep[x]);
        vector<pair<long long, int>> ngd;
        for (int i = 0, j = 0; i < gd.size(); i = j) {
            for (j = i; j < gd.size() && gd[i].first == gd[j].first; ++j);
            ngd.emplace_back(gd[i].first, gd[i].second);
        }
        int res = Count(ngd, dep[x]);
        for (int u : g[x]) {
            if (u == p) continue;
            res += Dfs(u, x, ngd);
            if (res >= kMod) res -= kMod;
        }
        return res;
    };

    printf("%d\n", Dfs(0, -1, vector<pair<long long, int>>()));
    return 0;
}