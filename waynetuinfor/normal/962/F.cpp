#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
vector<pair<int, int>> g[maxn];
int low[maxn], tin[maxn], t;
int bcc[maxn], sz;
int a[maxn], b[maxn], deg[maxn];
bool cut[maxn], ins[maxn];

vector<int> ed[maxn];

stack<int> st;

void dfs(int x, int p) {
    tin[x] = low[x] = ++t;
    int ch = 0;
    for (auto u : g[x]) if (u.first != p) {
        if (!ins[u.second]) st.push(u.second), ins[u.second] = true;
        if (tin[u.first]) {
            low[x] = min(low[x], tin[u.first]);
            continue;
        }
        ++ch;
        dfs(u.first, x);
        low[x] = min(low[x], low[u.first]);
        if (low[u.first] >= tin[x]) {
            cut[x] = true;
            ++sz;
            while (true) {
                int e = st.top(); st.pop();
                bcc[e] = sz;
                if (e == u.second) break;
            }
        }
    }
    if (ch == 1 && p == -1) cut[x] = false;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        --u, --v;
        a[i] = u, b[i] = v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    for (int i = 0; i < n; ++i) if (!tin[i]) dfs(i, -1);
    for (int i = 0; i < m; ++i) ed[bcc[i]].push_back(i);
    // for (int i = 0; i < m; ++i) printf("%d ", bcc[i]); puts("");
    vector<int> ans;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 0; j < ed[i].size(); ++j) deg[a[ed[i][j]]] = deg[b[ed[i][j]]] = 0;
        for (int j = 0; j < ed[i].size(); ++j) ++deg[a[ed[i][j]]], ++deg[b[ed[i][j]]];
        bool ok = true;
        for (int j = 0; j < ed[i].size(); ++j) ok &= (deg[a[ed[i][j]]] == 2 && deg[b[ed[i][j]]] == 2);
        if (ok) for (int j = 0; j < ed[i].size(); ++j) ans.push_back(ed[i][j]);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i] + 1);
    puts("");
    return 0;
}