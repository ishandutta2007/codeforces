#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }

    vector<vector<int>> E(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<vector<int>> costs(n);
    for (int x = 0; x < k; ++x) {
        vector<int> dist(n, -1);
        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (a[u] == x) {
                dist[u] = 0;
                q.push(u);
            }
        }
        while (not empty(q)) {
            int u = q.front();
            q.pop();
            for (auto v : E[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int u = 0; u < n; ++u) costs[u].push_back(dist[u]);
    }

    for (int u = 0; u < n; ++u) {
        sort(all(costs[u]));
        int ans = accumulate(begin(costs[u]), begin(costs[u]) + s, 0);
        cout << ans << "\n "[u + 1 < n];
    }

    exit(0);
}