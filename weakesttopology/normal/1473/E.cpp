#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using sint = short int;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

template<typename T>
vector<T> dijkstra(int s, const auto& E)
{
    struct Data
    {
        T key;
        int v;
        Data(T key, int v) : key(key), v(v) { }
        bool operator<(const Data& rhs) const { return key > rhs.key; }
    };
    vector<T> dist(size(E), T(LINF));
    priority_queue<Data> pq;
    pq.emplace(dist[s] = 0, s);
    while (not empty(pq))
    {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : E[u])
        {
            if (chmin(dist[v], dist[u] + w))
                pq.emplace(dist[v], v);
        }
    }
    return dist;
}

int main()
{ _
    int n, m; cin >> n >> m;

    int N = 4 * n;

    vector<vector<pair<int, ll>>> E(N);

    auto get = [&](int mask, int u) { return mask * n + u; };

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        ll w; cin >> w;

        for (int t = 0; t < 2; ++t)
        {
            for (int mask = 0; mask < 4; ++mask)
            {
                E[get(mask, u)].emplace_back(get(mask, v), +w);

                if ((mask & 1) == 0)
                    E[get(mask, u)].emplace_back(get(mask | 1, v), 2 * w);
                if ((mask & 2) == 0)
                    E[get(mask, u)].emplace_back(get(mask | 2, v), 0);
            }

            swap(u, v);
        }
    }

    auto dist = dijkstra<ll>(get(0, 0), E);

    for (auto [v, w] : E[get(0, 0)])
        if (v < n) chmin(dist[get(3, v)], w);

    for (int u = 1; u < n; ++u)
    {
        cout << dist[get(3, u)] << "\n "[u + 1 < n];
    }

    exit(0);
}