#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 5;
int D1[505], D2[505], D3[505];
int E[505][505], n;

void dijkstra(int D[]) {
    bool vis[505] = {};
    for (int it = 1; it <= n; ++it) {
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            if (D[i] <= D[x]) x = i;
        }
        vis[x] = 1;
        for (int i = 1; i <= n; ++i) {
            if (E[x][i] == inf) continue;
            D[i] = min(D[i], D[x] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) E[i][j] = inf;
        for (int i = 1; i <= m; ++i) {
            int x, y, w;
            cin >> x >> y >> w;
            E[x][y] = E[y][x] = min(E[x][y], w);
        }
        for (int i = 0; i <= n; ++i) {
            D1[i] = D2[i] = D3[i] = inf;
        }
        D1[1] = D2[n] = 0;
        dijkstra(D1);
        dijkstra(D2);
        for (int i = 1; i <= n; ++i) {
            D3[i] = min(D1[i] + D2[i], inf);
        }
        dijkstra(D3);
        long long ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (E[i][j] == inf) continue;
                ans = min(ans, E[i][j] * min({ D1[i] + D2[j] + 1ll, D2[i] + D1[j] + 1ll, D3[i] + 2ll, D3[j] + 2ll }));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}