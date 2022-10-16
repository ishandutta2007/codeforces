#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> d(N, vector<int>(N, inf));
    vector<array<int, 3>> edges(M);
    for (auto& [u, v, b] : edges) {
        cin >> u >> v >> b;
        --u, --v;
        if (b == 0) {
            d[u][v] = d[v][u] = 1;
        } else {
            d[v][u] = -1;
            d[u][v] = +1;
        }
    }
    for (int u = 0; u < N; ++u) {
        d[u][u] = 0;
    }
    for (int v = 0; v < N; ++v) {
        for (int u = 0; u < N; ++u) {
            for (int w = 0; w < N; ++w) {
                d[u][w] = min(d[u][w], d[u][v] + d[v][w]);
            }
        }
    }
    int ans = -1, best = -1;
    for (int s = 0; s < N; ++s) {
        bool good = true;
        for (auto [u, v, b] : edges) {
            if (abs(d[s][u] - d[s][v]) != 1 || (b && d[s][v] != d[s][u] + 1)) {
                good = false;
                break;
            }
        }
        int cost = *max_element(d[s].begin(), d[s].end()) - *min_element(d[s].begin(), d[s].end());
        if (good && cost > ans) {
            ans = cost;
            best = s;
        }
    }
    if (ans == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << ans << '\n';
        int offset = *min_element(d[best].begin(), d[best].end());
        for (int u = 0; u < N; ++u) {
            cout << d[best][u] - offset << "\n "[u + 1 < N];
        }
    }
    exit(0);
}