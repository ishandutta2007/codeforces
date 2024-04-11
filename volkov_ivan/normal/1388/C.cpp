#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
vector <int> g[N];
int p[N], a[N], h[N];
bool ans;

int dfs(int v, int par = -1) {
    int s = 0;
    int sz = p[v];
    for (int u : g[v]) {
        if (u != par) {
            sz += dfs(u, v);
            s += a[u];
        }
    }
    if ((h[v] + sz) % 2 != 0) ans = 0;
    a[v] = (h[v] + sz) / 2;
    //cout << v << ' ' << a[v] << ' ' << sz << endl;
    if (a[v] < s || a[v] < 0 || a[v] > sz) ans = 0;
    return sz;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();
        ans = 1;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        dfs(1);
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}