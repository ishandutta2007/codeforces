#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3007;
vector <int> g[N];
short dst[N][N], prv[N][N], sz[N][N];
long long dp[N][N];

void dfs(int s, int v, int p = -1, int d = 0) {
    dst[s][v] = d;
    prv[s][v] = p;
    sz[s][v] = 1;
    for (int u : g[v]) {
        if (u != p) {
            dfs(s, u, v, d + 1);
            sz[s][v] += sz[s][u];
        }
    }
}

bool cmp(pair <int, int> a, pair <int, int> b) {
    return (dst[a.first][a.second] < dst[b.first][b.second]);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) dfs(i, i);
    vector <pair <int, int>> vc;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vc.push_back({i, j});
        }
    }
    sort(vc.begin(), vc.end(), cmp);
    long long maxi = 0;
    for (auto elem : vc) {
        int v = elem.first, u = elem.second;
        if (dst[v][u] == 1) {
            dp[u][v] = dp[v][u] = ((int) sz[v][u]) * ((int) sz[u][v]);
            maxi = max(maxi, dp[v][u]);
            continue;
        }
        int pv = prv[u][v], pu = prv[v][u];
        dp[u][v] = dp[v][u] = ((int) sz[v][u]) * ((int) sz[u][v]) + max(dp[pv][u], dp[v][pu]);
        maxi = max(maxi, dp[v][u]);
    }
    cout << maxi << endl;
    return 0;
}