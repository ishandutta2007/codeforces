#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int c, ans[maxn];
vector<int> G[maxn], p[maxn], b[4], gan[maxn];

bool v[maxn];

void dfs(int now) {
    v[now] = true;
    p[c].push_back(now);
    for (int u : G[now]) if (!v[u]) dfs(u);
}

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) ++c, dfs(i);
    for (int i = 1; i <= c; ++i) if (p[i].size() > 3) return cout << "-1" << endl, 0;
    for (int i = 1; i <= c; ++i) {
        b[p[i].size()].push_back(i);
    }
    int t = 0;
    for (int i : b[3]) {
        ++t;
        for (int j : p[i]) ans[j] = t;
    }
    if (b[2].size() > b[1].size()) return cout << "-1" << endl, 0;
    for (int i = 0; i < b[2].size(); ++i) {
        ++t;
        for (int j : p[b[2][i]]) ans[j] = t;
        for (int j : p[b[1][i]]) ans[j] = t;
    }
    if ((b[1].size() - b[2].size()) % 3) return cout << "-1" << endl, 0;
    for (int i = b[2].size(); i < b[1].size(); i += 3) {
        ++t;
        ans[p[b[1][i]][0]] = t;
        ans[p[b[1][i + 1]][0]] = t;
        ans[p[b[1][i + 2]][0]] = t;
    }
    for (int i = 1; i <= n; ++i) gan[ans[i]].push_back(i);
    for (int i = 1; i <= t; ++i) {
        for (int j : gan[i]) cout << j << ' '; cout << endl;
    }
    return 0;
}