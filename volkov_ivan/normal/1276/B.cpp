#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
vector <int> g[N];
bool vis[N];
int cnt[N];

int dfs(int v, int forbid) {
    vis[v] = 1;
    if (v == forbid) return 1;
    int res = 1;
    vis[v] = 1;
    cnt[v]++;
    for (int u : g[v]) {
        if (!vis[u]) res += dfs(u, forbid);
    }
    return res;
}

int dfs2(int v, int a, int b) {
    if (cnt[v] == 2) return 0;
    vis[v] = 1;
    int res = 1;
    if (v == a || v == b) return res;
    for (int u : g[v]) {
        if (!vis[u]) res += dfs2(u, a, b);
    }
    return res;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int x = n - dfs(a, b);
    memset(vis, 0, sizeof(vis));
    int y = n - dfs(b, a);
    int ob = 0;
    //for (int i = 1; i <= n; i++) if (cnt[i] == 2) ob++;
    x -= ob;
    y -= ob;
    cout << x * y << "\n";
    return;
    memset(vis, 0, sizeof(vis));
    int summ = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int x = dfs2(i, a, b);
            if (x != 0) {
                //cout << x << endl;
                x--;
                res += x * summ;
                summ += x;
            }
        }
    }
    cout << summ << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}