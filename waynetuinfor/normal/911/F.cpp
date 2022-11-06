#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int d[2][maxn], p[maxn], deg[maxn];

void dfs(int now, int fa, int dep, int idx) {
    if (~idx) d[idx][now] = dep;
    p[now] = fa;
    for (int u : G[now]) if (u != fa) dfs(u, now, dep + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 0, 0);
    int bst = -1;
    for (int i = 1; i <= n; ++i) {
        if (bst == -1 || d[0][i] > d[0][bst]) bst = i;
    }
    dfs(bst, 0, 0, 0);
    int to = -1;
    for (int i = 1; i <= n; ++i) {
        if (to == -1 || d[0][i] > d[0][to]) to = i;
    }
    dfs(to, 0, 0, 1);
    int diameter = d[1][bst], now = to;
    for (int i = 0; i < diameter / 2; ++i) now = p[now];
    int center = now;
    dfs(center, 0, 0, -1);
    queue<int> leaf;
    for (int i = 1; i <= n; ++i) {
        if (i == bst || i == to) continue;
        if (G[i].size() == 1 && G[i][0] == p[i]) leaf.push(i);
        else deg[i] = G[i].size() - 1;
    }
    long long ans = 0;
    vector<tuple<int, int, int>> vec;
    int ver[2] = { bst, to };
    // cout << "bst = " << bst << " to = " << to << endl;
    while (leaf.size()) {
        int now = leaf.front(); leaf.pop();
        int idx = (d[0][now] > d[1][now] ? 0 : 1);
        ans += d[idx][now];
        vec.emplace_back(ver[idx], now, now);
        for (int u : G[now]) {
            --deg[u];
            if (deg[u] == 0) leaf.push(u);
        }
    }
    // cout << "done leaf" << endl;
    dfs(to, 0, 0, 1);
    now = bst;
    for (now; now != to; now = p[now]) {
        ans += diameter; --diameter;
        vec.emplace_back(now, to, now);
    }
    cout << ans << endl;
    assert(vec.size() == n - 1);
    for (auto i : vec) {
        int a, b, c; tie(a, b, c) = i;
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}