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

template<typename T>
vector<T> dijkstra(int s, const auto& E) {
    vector<T> dist(size(E), numeric_limits<T>::max());
    priority_queue<pair<T, int>> pq;
    pq.emplace(dist[s] = 0, s);
    while (not empty(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (-d > dist[u]) continue;
        for (auto [v, w] : E[u]) {
            if (chmin(dist[v], dist[u] + w)) pq.emplace(-dist[v], v);
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n);

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        res += a[i].second;
    }

    sort(all(a));

    vector<vector<pair<int, ll>>> E(2 * n);

    for (int u = 0; u + 1 < n; ++u) {
        E[u + 1].emplace_back(u, 0);
        E[n + u].emplace_back(n + u + 1, a[u + 1].first - a[u].first);
        E[n + u].emplace_back(u, 0);

        auto iter = upper_bound(all(a), pair(a[u].first + a[u].second, -LINF));
        int v = (int)distance(begin(a), iter);

        if (u + 1 < v) E[u].emplace_back(v - 1, 0);
        if (v < n) E[u].emplace_back(n + v, a[v].first - (a[u].first + a[u].second));
    }
    E[2 * n - 1].emplace_back(n - 1, 0);

    auto dist = dijkstra<ll>(0, E);
    res += dist[n - 1];

    cout << res << endl;

    exit(0);
}