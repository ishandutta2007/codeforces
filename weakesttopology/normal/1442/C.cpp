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

bool chmin(auto& x, auto y)
{
    return y < x ? x = y, true : false;
}

auto sum(const auto& p1, const auto& p2)
{
    return pair(p1.first + p2.first, p1.second + p2.second);
}

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    while (p > 0)
    {
        if (p & 1) res = res * x % mod;
        p >>= 1, x = x * x % mod;
    }
    return res;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vector edges(m, pair(0, 0));

    for (auto& [u, v] : edges) { cin >> u >> v; --u, --v; }

    int N = 2 * n;

    vector E(N, vector(0, pair(0, 0)));

    for (auto [u, v] : edges)
        E[u].emplace_back(v, 0), E[n + v].emplace_back(n + u, 0);

    for (int u = 0; u < n; ++u)
        E[u].emplace_back(u + n, 1), E[u + n].emplace_back(u, 1);

    auto dijkstra = [&](int s, auto& E)
    {
        vector dist(size(E), INF); dist[s] = 0;
        struct Data
        {
            int key; int v;
            Data(int key, int v) : key(key), v(v) { }
            bool operator<(const Data& rhs) const { return key > rhs.key; }
        };
        priority_queue<Data> pq; pq.push(Data{ 0, s });
        while (not empty(pq))
        {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : E[u])
                if (chmin(dist[v], dist[u] + w)) pq.emplace(dist[v], v);
        }
        return dist;
    };

    auto distflip = dijkstra(0, E);

    int minflip = min(distflip[n - 1], distflip[2 * n - 1]);

    debug(minflip);

    constexpr int K = 20;

    int ans = INF;

    if (minflip < K)
    {
        auto id = [&](int u, int level) { return level * n + u; };

        vector F(n * K, vector(0, pair(0, 0)));

        for (int j = 0; j < K; ++j)
            for (auto [u, v] : edges)
            {
                if (j & 1) swap(u, v);
                F[id(u, j)].emplace_back(id(v, j), 1);
            }
        for (int j = 0; j < K - 1; ++j)
            for (int u = 0; u < n; ++u)
                F[id(u, j)].emplace_back(id(u, j + 1), 1 << j);

        auto dist = dijkstra(0, F);

        for (int j = 0; j < K; ++j)
            ans = min(ans, dist[id(n - 1, j)]);
    }
    else
    {
        auto lexdijkstra = [&](int s, auto& E)
        {
            vector dist(size(E), pair(INF, INF)); dist[s] = pair(0, 0);
            struct Data
            {
                pair<int, int> key; int v;
                Data(pair<int, int> key, int v) : key(key), v(v) { }
                bool operator<(const Data& rhs) const { return key > rhs.key; }
            };
            priority_queue<Data> pq; pq.emplace(dist[s], s);
            while (not empty(pq))
            {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w] : E[u])
                    if (chmin(dist[v], sum(dist[u], w))) pq.emplace(dist[v], v);
            }
            return dist;
        };

        vector Ep(N, vector(0, pair(0, pair(0, 0))));

        for (auto [u, v] : edges)
        {
            Ep[u].emplace_back(v, pair(0, 1));
            Ep[v + n].emplace_back(u + n, pair(0, 1));
        }

        for (int u = 0; u < n; ++u)
        {
            Ep[u].emplace_back(u + n, pair(1, 0));
            Ep[u + n].emplace_back(u, pair(1, 0));
        }

        auto lexdist = lexdijkstra(0, Ep);

        auto minlex = min(lexdist[n - 1], lexdist[2 * n - 1]);

        debug(minlex.first);
        debug(minlex.second);

        ll mod = 998244353LL;

        ans = int((modpow(2LL, minlex.first, mod) + mod - 1 + minlex.second) % mod);
    }

    cout << ans << endl;

    exit(0);
}