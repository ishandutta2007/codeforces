#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
vector<int> g[kN];
int dp[kN], fr[kN];

void Dfs(int x, int p) {
    dp[x] = 0;
    fr[x] = x;
    for (int u : g[x]) {
        if (u == p) continue;
        Dfs(u, x);
        if (dp[u] + 1 > dp[x]) {
            dp[x] = dp[u] + 1;
            fr[x] = fr[u];
        }
    }
}

tuple<int, int, int, int> Dfs2(int x, int p, int f = -1, int z = -1) {
    multiset<pair<int, int>> s;
    for (int u : g[x]) {
        if (u == p) continue;
        s.insert(make_pair(dp[u] + 1, fr[u]));
    }
    tuple<int, int, int, int> res = make_tuple(0, 0, 0, 0);
    if (z != -1) s.insert(make_pair(f + 1, z));
    if (s.size() >= 3) {
        get<0>(res) = prev(s.end())->first + prev(prev(s.end()))->first + prev(prev(prev(s.end())))->first;
        get<1>(res) = prev(s.end())->second;
        get<2>(res) = prev(prev(s.end()))->second;
        get<3>(res) = prev(prev(prev(s.end())))->second;
    }
    if (s.size() >= 2) {
        int u = prev(s.end())->first + prev(prev(s.end()))->first;
        if (u > get<0>(res)) {
            get<0>(res) = u;
            get<1>(res) = prev(s.end())->second;
            get<2>(res) = prev(prev(s.end()))->second;
            get<3>(res) = x;
        }
    }
    if (z == -1) s.insert(make_pair(f + 1, x));
    for (int u : g[x]) {
        if (u == p) continue;
        s.erase(s.find(make_pair(dp[u] + 1, fr[u])));
        res = max(res, Dfs2(u, x, prev(s.end())->first, prev(s.end())->second));
        s.insert(make_pair(dp[u] + 1, fr[u]));
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Dfs(0, -1);
    auto ans = Dfs2(0, -1);
    printf("%d\n", get<0>(ans));
    printf("%d %d %d\n", get<1>(ans) + 1, get<2>(ans) + 1, get<3>(ans) + 1);
}