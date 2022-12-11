#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> g[N];
int dst[N];

void dfs(int v, int par = -1, int d = 0) {
    dst[v] = d;
    for (int u : g[v]) {
        if (u != par) dfs(u, v, d + 1);
    }
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(a);
    if (dst[b] <= da) {
        cout << "Alice\n";
        return;
    }
    int p = a;
    for (int i = 1; i <= n; i++) if (dst[i] > dst[p]) p = i;
    dfs(p);
    int maxi = -1;
    for (int i = 1; i <= n; i++) maxi = max(maxi, dst[i]);
    int bb = min(db, maxi);
    //cout << bb << endl;
    if (bb > 2 * da) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
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