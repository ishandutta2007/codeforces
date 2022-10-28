#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector same(n, vector(n, vector(n, true)));
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j) {
            string s; cin >> s;
            for (int k = 0; k < n; ++k) {
                same[i][j][k] = same[j][i][k] = (s[k] == '1');
            }
            same[i][i][j] = true;
        }
    }

    for (int i = 1; i < n; ++i) {
        vector dist(n, vector(n, n));
        dist[0][i] = dist[i][0] = 1;
        for (int j = 0; j < n; ++j) dist[j][j] = 0;

        vector par(n, -1);
        par[i] = 0, par[0] = i;

        bool loop = true;
        while (loop) {
            loop = false;
            for (int u = 0; u < n; ++u) {
                if (par[u] == -1) continue;
                for (int v = 0; v < n; ++v) {
                    if (par[v] == -1 && same[par[u]][v][u]) {
                        dist[u][v] = dist[v][u] = 1;
                        par[v] = u;
                        loop = true;
                    }
                }
            }
        }

        for (int w = 0; w < n; ++w) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
                }
            }
        }

        bool valid = !count(par.begin(), par.end(), -1);
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                for (int w = 0; w < n; ++w) {
                    valid &= (dist[u][w] == dist[v][w]) == same[u][v][w];
                }
            }
        }

        if (valid) {
            cout << "Yes\n";
            for (int j = 1; j < n; ++j) {
                cout << j + 1 << " " << par[j] + 1 << "\n";
            }
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}