#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int c[maxn], node, nd[maxn], f, mx;
vector<int> G[maxn], ed[maxn];
bool v[maxn];

void dfs1(int now, int color) {
    nd[now] = node;
    for (int u : G[now]) {
        if (!nd[u] && c[u] == color) dfs1(u, color);
    }
}

void dfs2(int now, int dis) {
    v[now] = true; 
    if (dis > mx) {
        mx = dis;
        f = now;
    }
    for (int u : ed[now]) if (!v[u]) {
        dfs2(u, dis + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!nd[i]) {
        ++node;
        dfs1(i, c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int u : G[i]) if (nd[u] != nd[i]) {
            ed[nd[i]].emplace_back(nd[u]);
            ed[nd[u]].emplace_back(nd[i]);
        }
    }
    dfs2(1, 0);
    memset(v, false, sizeof(v));
    mx = 0;
    dfs2(f, 0);
    cout << (mx + 1) / 2 << endl;
    return 0;
}