#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
int a[maxn], b[maxn], tin[maxn], t, low[maxn], bcc[maxn], bcnt, to[maxn];
vector<pair<int, int>> G[maxn];
vector<int> head;
bool v[maxn], bridge[maxn];
stack<int> edge;

void dfs(int now, int fa) {
    tin[now] = low[now] = ++t;
    for (auto u : G[now]) if (u.first != fa) {
        edge.push(u.second);
        if (tin[u.first]) {
            low[now] = min(low[now], tin[u.first]);
            continue;
        }
        dfs(u.first, now);
        low[now] = min(low[now], low[u.first]);
        if (low[u.first] > tin[now]) {
            ++bcnt;
            do {
                int k = edge.top(); edge.pop();
                if (k == u.second) break;
                bcc[k] = bcnt;
            } while (true);
            bridge[u.second] = true;
        }
    }
}

int dfs2(int now) {
    v[now] = true;
    int ret = 1;
    for (auto u : G[now]) if (!v[u.first]) {
        if (!bridge[u.second]) ret += dfs2(u.first);
    }
    return ret;
}

void dfs3(int now, int fa) {
    v[now] = true;
    for (auto u : G[now]) if (u.first != fa) {
        if (bridge[u.second]) to[u.second] = now;
        else if (!to[u.second]) to[u.second] = now;
        if (!v[u.first]) dfs3(u.first, now);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        G[a[i]].emplace_back(b[i], i);
        G[b[i]].emplace_back(a[i], i);
    }
    dfs(1, 0);
    int ans = 0, root = -1;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int sz = dfs2(i);
        if (sz > ans) ans = sz, root = i;
    }
    memset(v, false, sizeof(v));
    dfs3(root, 0);
    cout << ans << endl;
    for (int i = 0; i < m; ++i) {
        if (a[i] == to[i]) cout << b[i] << ' ' << a[i] << endl;
        else cout << a[i] << ' ' << b[i] << endl;
    }
    return 0;
}