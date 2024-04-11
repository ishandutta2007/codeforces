#include <bits/stdc++.h>
using namespace std;

const int N = 300001;

set<pair<int, int>> adj[N][3];
array<int, 3> edges[N];

vector<int> paths[N];

int flipped[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int id = 1; id <= m; ++id) {
        auto &[u, v, w] = edges[id];
        cin >> u >> v >> w;

        adj[u][w].insert({v, id});
        adj[v][w].insert({u, -id});

        paths[id] = {id};
    }

    int odyssey = 0;

    for (int k = 2; k >= 0; --k) {
        for (int u = 1; u <= n; ++u) {
            while (adj[u][k].size() > 1) {
                auto [s, id_s] = *adj[u][k].begin();
                adj[u][k].erase(adj[u][k].begin());
                adj[s][k].erase({u, -id_s});

                auto [t, id_t] = *adj[u][k].begin();
                adj[u][k].erase(adj[u][k].begin());
                adj[t][k].erase({u, -id_t});

                if (paths[abs(id_s)].size() > paths[abs(id_t)].size()) {
                    swap(s, t), swap(id_s, id_t);
                }

                if ((long long) id_s * id_t > 0) {
                    for (auto v : paths[abs(id_s)]) {
                        flipped[v] ^= true;
                    }
                }

                for (auto v : paths[abs(id_s)]) {
                    paths[abs(id_t)].push_back(v);
                }


                if (s != t) {
                    adj[s][k].insert({t, id_t});
                    adj[t][k].insert({s, -id_t});
                }
            }
        }

        if (k > 0) {
            for (int u = 1; u <= n; ++u) {
                if (k == 1) {
                    odyssey += adj[u][k].size();
                }

                for (auto [v, id] : adj[u][k]) {
                    adj[u][0].insert({v, id});
                }
            }
        }
    }

    cout << odyssey << "\n";
    for (int i = 1; i <= m; ++i) {
        cout << (flipped[i] ? 2 : 1);
    }
    cout << "\n";
}