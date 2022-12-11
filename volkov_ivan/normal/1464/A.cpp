#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
vector <int> g[2 * N];
bool vis[N];

int cnt = 0;

bool dfs(int v, int pr = -1) {
    vis[v] = 1;
    cnt++;
    for (int u : g[v]) {
        if (u == pr)
            continue;
        if (vis[u])
            return 1;
        if (dfs(u, v))
            return 1;
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m + 3; i++) {
        g[i].clear();
        vis[i] = 0;
    }
    vector <int> here[n + 1];
    bool used[m];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        used[i] = 1;
        if (x == y) {
            used[i] = 0;
            continue;
        }
        here[x].push_back(i);
        here[y].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (here[i].size() == 2) {
            g[here[i][0]].push_back(here[i][1]);
            g[here[i][1]].push_back(here[i][0]);
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (!vis[i] && used[i]) {
            cnt = 0;
            if (dfs(i)) {
                res++;
            }
            res += cnt;
        }
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
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}