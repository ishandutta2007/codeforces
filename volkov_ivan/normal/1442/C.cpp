#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 8e5 + 7, INF = 1e9 + 7, K = 19, INF2 = INF * INF, M = 998244353;
signed dp0[K][N];
vector <signed> g[N];
vector <signed> g2[N];
vector <signed> has_dist[N];
int dst[2][N];

void calc_0(int n) {
    for (int i = 0; i < K; i++)
        for (int j = 1; j <= n; j++) 
            dp0[i][j] = INF;
    dp0[0][1] = 0;
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) has_dist[i].clear();
        for (int i = 1; i <= n; i++) {
            if (dp0[k][i] != INF)
                has_dist[dp0[k][i]].push_back(i);
        }
        for (signed dst = 0; dst < N; dst++) {
            for (signed v : has_dist[dst]) {
                if (dp0[k][v] != dst)
                    continue;
                if (k != K - 1) dp0[k + 1][v] = min(dp0[k + 1][v], dp0[k][v] + (1 << k));
                if (k % 2 == 0) {
                    for (signed u : g[v]) {
                        if (dp0[k][u] > dp0[k][v] + 1) {
                            dp0[k][u] = dp0[k][v] + 1;
                            has_dist[dp0[k][u]].push_back(u);
                        }
                    }
                } else {
                    for (signed u : g2[v]) {
                        if (dp0[k][u] > dp0[k][v] + 1) {
                            dp0[k][u] = dp0[k][v] + 1;
                            has_dist[dp0[k][u]].push_back(u);
                        }
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g2[u].push_back(v);
    }
    calc_0(n);
    signed res = INF;
    for (int i = 0; i < K; i++) res = min(res, dp0[i][n]);
    if (res != INF) {
        cout << res << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dst[0][i] = dst[1][i] = INF2;
    }
    set <pair <int, pair <signed, signed>>> q;
    dst[0][1] = 0;
    q.insert({0, {0, 1}});
    while (!q.empty()) {
        auto [d, vv] = *q.begin();
        auto [k, v] = vv;
        q.erase(q.begin());
        if (dst[1 - k][v] > dst[k][v] + INF) {
            if (dst[1 - k][v] != INF2) {
                q.erase({dst[1 - k][v], {1 - k, v}});
            }
            dst[1 - k][v] = dst[k][v] + INF;
            q.insert({dst[1 - k][v], {1 - k, v}});
        }
        if (k % 2 == 0) {
            for (int u : g[v]) {
                if (dst[k][u] > dst[k][v] + 1) {
                    if (dst[k][u] != INF2) {
                        q.erase({dst[k][u], {k, u}});
                    }
                    dst[k][u] = dst[k][v] + 1;
                    q.insert({dst[k][u], {k, u}});
                }
            }
        } else {
            for (int u : g2[v]) {
                if (dst[k][u] > dst[k][v] + 1) {
                    if (dst[k][u] != INF2) {
                        q.erase({dst[k][u], {k, u}});
                    }
                    dst[k][u] = dst[k][v] + 1;
                    q.insert({dst[k][u], {k, u}});
                }
            }
        }
    }
    int ans = min(dst[0][n], dst[1][n]);
    int cnt = ans / INF, real = ans % INF;
    int res2 = 1;
    for (int i = 0; i < cnt; i++) res2 = (res2 * 2) % M;
    res2 = (res2 + M - 1) % M;
    res2 = (res2 + real) % M;
    cout << res2 << endl;
    return 0;
}