#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int dep[maxn], p[20][maxn];

void dfs(int now, int fa, int d) {
    dep[now] = d; p[0][now] = fa;
    for (int i = 1; i < 20; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
}

int lca(int a, int b) {
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
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[i].push_back(p); G[p].push_back(i);
    }
    dfs(1, 0, 0);
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        int v1 = lca(a, b), v2 = lca(b, c), v3 = lca(c, a);
        int v = v1 ^ v2 ^ v3;
        cout << max({ dis(a, v), dis(b, v), dis(c, v) }) + 1 << endl;
    }
    return 0;
}