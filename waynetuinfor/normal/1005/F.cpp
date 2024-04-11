#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<pair<int, int>> g[maxn];
vector<int> dp[maxn];
vector<int> s;
vector<vector<int>> ans;
int d[maxn], n, m, k;

void dfs(int x) {
    if (k == 0) return;
    if (x == n + 1) {
        --k;
        ans.push_back(s);
        return;
    }
    for (int i = 0; i < dp[x].size(); ++i) {
        s[dp[x][i]] = 1;
        dfs(x + 1);
        s[dp[x][i]] = 0;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    queue<int> q;
    fill_n(d, maxn, maxn);
    d[1] = 0;
    q.push(1);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto u : g[x]) {
            if (d[x] + 1 < d[u.first]) d[u.first] = d[x] + 1, dp[u.first] = { u.second }, q.push(u.first);
            else if (d[x] + 1 == d[u.first]) dp[u.first].push_back(u.second);
        }
    }
    s.resize(m);
    dfs(2);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < m; ++j) printf("%d", ans[i][j]);
        puts("");
    }
}