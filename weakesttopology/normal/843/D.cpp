#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> E(n);
    vector<int> from(m), to(m);
    vector<ll> w(m);

    for (int j = 0; j < m; ++j) {
        int &u = from[j], &v = to[j];
        cin >> u >> v >> w[j];
        --u, --v;
        E[u].push_back(j);
    }

    vector<ll> dist(n, LINF), distnxt(n, LINF);

    priority_queue<pair<ll, int>> pq;
    pq.emplace(dist[0] = 0, 0);
    while (not empty(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (-d != dist[u]) continue;
        for (auto j : E[u]) {
            int v = to[j];
            if (chmin(dist[v], dist[u] + w[j])) pq.emplace(-dist[v], v);
        }
    }

    vector<bool> vis(n);
    vector<queue<int>> buckets(m + 1);

    auto d = [&](int j){ return dist[from[j]] - dist[to[j]]; };

    for (int z = 0; z < q; ++z) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            --v;
            ll ans = dist[v];
            if (ans >= LINF) ans = -1;
            cout << ans << endl;
        }
        else {
            int k;
            cin >> k;
            vector<int> U(k);
            for (auto& j : U) {
                cin >> j;
                --j;
                w[j] += 1;
            }

            fill(all(vis), false);
            fill(all(distnxt), k);

            distnxt[0] = 0;
            buckets[0].push(0);

            for (int x = 0; x <= k; ++x) {
                auto& q = buckets[x];
                while (not empty(q)) {
                    int u = q.front();
                    q.pop();
                    if (vis[u]) continue;
                    vis[u] = true;
                    for (auto j : E[u]) {
                        int v = to[j];
                        if (chmin(distnxt[v], distnxt[u] + w[j] + d(j)) && distnxt[v] <= k) {
                            buckets[distnxt[v]].push(v);
                        }
                    }
                }
            }

            for (int u = 0; u < n; ++u) {
                dist[u] = min(dist[u] + distnxt[u], LINF);
            }
        }
    }

    exit(0);
}