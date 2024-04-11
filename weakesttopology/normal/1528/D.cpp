#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 600;
int C[nmax][nmax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(C, 0x3f, sizeof(C));

    for (int j = 0; j < m; ++j) {
        int u, v, c;
        cin >> u >> v >> c;
        C[u][v] = c;
    }

    vector<int> dist(n);
    vector<bool> vis(n);

    for (int src = 0; src < n; ++src) {
        for (int v = 0; v < n; ++v) dist[v] = C[src][v], vis[v] = false;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int v = 0; v < n; ++v) {
                if (not vis[v] && (u == -1 || dist[v] < dist[u])) u = v;
            }
            vis[u] = true;
            for (int v = 0; v < n; ++v) {
                int nv = (v + dist[u]) % n;
                dist[nv] = min(dist[nv], dist[u] + C[u][v]);
            }
            int v = (u + 1) % n;
            dist[v] = min(dist[v], dist[u] + 1);
        }
        dist[src] = 0;
        for (int u = 0; u < n; ++u) {
            cout << dist[u] << "\n "[u + 1 < n];
        }
    }

    exit(0);
}