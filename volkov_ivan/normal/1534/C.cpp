#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 1e9 + 7, N = 4e5 + 7;
vector <int> g[N];
int perm[N], perm2[N], wh[N];
bool vis[N];

void dfs(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
        if (!vis[u])
            dfs(u);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
        wh[perm[i]] = i;
        g[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> perm2[i];
    }
    for (int i = 1; i <= n; i++) {
        int other = wh[perm2[i]];
        g[i].push_back(other);
        g[other].push_back(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    int res = 1;
    for (int i = 0; i < cnt; i++) {
        res *= 2;
        while (res > M)
            res -= M;
    }
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}