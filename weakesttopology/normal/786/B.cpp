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

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

template<typename T>
vector<T> dijkstra(int s, const auto& E)
{
    vector<T> dist(size(E), T(LINF));
    priority_queue<pair<T, int>> pq;
    pq.emplace(dist[s] = 0, s);
    while (not empty(pq))
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (-d > dist[u]) continue;
        for (auto [v, w] : E[u])
        {
            if (chmin(dist[v], dist[u] + w)) pq.emplace(-dist[v], v);
        }
    }
    return dist;
}

int main()
{ _
    int n, q, s;
    cin >> n >> q >> s;
    --s;

    vector<vector<pair<int, ll>>> E(3 * n);
    int ptr = n;

    map<int, int> down, up;
    auto get = [&](auto& mp, int x)
    {
        return mp.count(x) ? mp[x] : mp[x] = ptr++;
    };
    for (int u = 0; u < n; ++u) down[n + u] = up[n + u] = u;

    for (int p = n - 1; p > 0; --p)
    {
        for (auto q : { p << 1, p << 1 | 1 })
        {
            E[get(up, q)].emplace_back(get(up, p), 0);
            E[get(down, p)].emplace_back(get(down, q), 0);
        }
    }

    for (int j = 0; j < q; ++j)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, u, w;
            cin >> v >> u >> w;
            --v, --u;
            E[v].emplace_back(u, w);
        }
        else
        {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            --v, --l, --r;
            if (t == 2)
            {
                for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
                {
                    if (l & 1) E[v].emplace_back(get(down, l++), w);
                    if (r & 1) E[v].emplace_back(get(down, --r), w);
                }
            }
            else
            {
                for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
                {
                    if (l & 1) E[get(up, l++)].emplace_back(v, w);
                    if (r & 1) E[get(up, --r)].emplace_back(v, w);
                }
            }
        }
    }

    auto dist = dijkstra<ll>(s, E);

    for (int u = 0; u < n; ++u)
    {
        ll res = dist[u] < LINF ? dist[u] : -1;
        cout << res << "\n "[u + 1 < n];
    }

    exit(0);
}