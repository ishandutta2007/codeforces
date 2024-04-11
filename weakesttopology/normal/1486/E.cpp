#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y){ return y < x ? (x = y, true) : false; }

int main()
{ _
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        E[u].emplace_back(v, w), E[v].emplace_back(u, w);
    }

    constexpr int wmax = 50;

    vector<ll> dist(n * (wmax + 1), LINF);
    auto Id = [&](int level, int u) { return level * n + u; };

    priority_queue<pair<ll, int>> pq;
    pq.emplace(dist[Id(0, 0)] = 0, Id(0, 0));

    while (not empty(pq))
    {
        auto [d, u] = pq.top();
        pq.pop();
        d *= -1;
        if (d > dist[u]) continue;
        int level = u / n;
        for (auto [v, w] : E[u % n])
        {
            if (level == 0 && chmin(dist[Id(w, v)], d))
                pq.emplace(-d, Id(w, v));
            if (level != 0 && chmin(dist[Id(0, v)], d + (level + w) * (level + w)))
                pq.emplace(-dist[Id(0, v)], Id(0, v));
        }
    }

    for (int u = 0; u < n; ++u)
    {
        ll res = dist[Id(0, u)];
        if (res >= LINF) res = -1;
        cout << res << "\n "[u + 1 < n];
    }

    exit(0);
}