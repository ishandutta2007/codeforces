#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int dep[maxn], p[20][maxn], sz[maxn];

void dfs(int now, int fa, int d) {
    p[0][now] = fa; dep[now] = d;
    for (int i = 1; i < 20; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
    }
    sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        sz[now] += sz[u];
    }
}

int lca(int a, int b) {
    if (a == b) return a;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < 20; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a]; b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

int dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 0);
    int m; cin >> m; while (m--) {
        int a, b; cin >> a >> b;
        if (dep[a] == dep[b]) {
            int v = lca(a, b);
            for (int i = 0; i < 20; ++i) {
                if ((dep[a] - dep[v] - 1) >> i & 1) a = p[i][a];
                if ((dep[b] - dep[v] - 1) >> i & 1) b = p[i][b];
            }
            cout << sz[1] - sz[a] - sz[b] << endl;
        } else {
            if (dep[a] > dep[b]) swap(a, b);
            int d = dis(a, b);
            if (d & 1) { cout << 0 << endl; continue; }
            int g = dep[b] - d / 2;
            for (int i = 0; i < 20; ++i) {
                if ((dep[b] - g - 1) >> i & 1) b = p[i][b];
            }
            cout << sz[p[0][b]] - sz[b] << endl;
        }
    }
    return 0;
}