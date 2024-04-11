#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
vector <int> g[N];
int sz[N], d[N], deg[N], cost[N];

void dfs(int v, int h = 0, int p = -1) {
    deg[v] = g[v].size();
    d[v] = h;
    sz[v] = 1;
    for (int u : g[v]) {
        if (u == p) continue;
        dfs(u, h + 1, v);
        sz[v] += sz[u];
    }
    cost[v] = d[v] - (sz[v] - 1);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set <pair <int, int>, greater <pair <int, int>>> s;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    if (k == n) {
        cout << 0 << endl;
    }
    dfs(1);
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (deg[i] == 1) {
            s.insert({cost[i], i});
        }
    }
    for (int i = 0; i < k; i++) {
        auto kek = *s.begin();
        s.erase(s.begin());
        res += kek.first;
        for (int elem : g[kek.second]) {
            if (--deg[elem] == 1 && elem != 1) {
                s.insert({cost[elem], elem});
            }
        }
    }
    cout << res << endl;
    return 0;
}