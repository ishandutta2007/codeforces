#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
vector<int> G[maxn];
int sz[maxn], dep[maxn], dis[maxn], tin[maxn], tout[maxn], t, p[lg][maxn], exc[maxn], n;

void dfs(int now, int fa, int d) {
    dep[now] = d;
    sz[now] = 1; dis[now] = 0;
    tin[now] = ++t;
    p[0][now] = fa;
    for (int i = 1; i < lg; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        sz[now] += sz[u];
        dis[now] += sz[u] + dis[u];
    }
    tout[now] = t;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a];
            b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

int getp(int v, int k) {
    for (int i = 0; i < lg; ++i) {
        if (k >> i & 1) {
            v = p[i][v];
            k -= (1 << i);
        }
    }
    return v;
}

int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

void dfs2(int now, int fa) {
    for (int u : G[now]) if (u != fa) {
        exc[u] = exc[now] + n - 2 * sz[u];
        dfs2(u, now);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    } 
    dfs(1, 0, 0); exc[1] = dis[1]; dfs2(1, 0);
    while (m--) {
        int a, b; cin >> a >> b;
        if (dep[a] > dep[b]) swap(a, b);
        double ans = 0.0;
        if (anc(a, b)) {
            int c = getp(b, dep[b] - dep[a] - 1);
            int ch = sz[b] * (n - sz[c]);
            int sum = (exc[a] - dis[c] - sz[c]) * sz[b] + (1 + dist(a, b)) * (n - sz[c]) * sz[b] + dis[b] * (n - sz[c]);
            ans = (double)sum / (double)ch;
        } else {
            int l = lca(a, b);
            int ch = sz[a] * sz[b];
            int sum = sz[b] * dis[a] + sz[a] * dis[b] + ch * (1 + dist(a, b));
            ans = (double)sum / (double)ch;
        }
        cout << fixed << setprecision(20) << ans << endl;
    }
    return 0;
}