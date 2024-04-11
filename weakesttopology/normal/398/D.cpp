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

int main()
{ _
    int n, m, q; cin >> n >> m >> q;

    int o; cin >> o;

    vector initial(o, 0);

    for (auto& u : initial) { cin >> u; --u; }

    vector edges(m, tuple(0, 0, 1));

    for (auto& [u, v, x] : edges)
    {
        cin >> u >> v; --u, --v;
        if (u > v) swap(u, v);
    }

    int M = 0;

    vector deg(n, 0);

    auto lazy = [&](int u) { return 1LL * deg[u] * deg[u] > M; };

    vector E(n, vector(0, pair(0, 0))), big(n, vector(0, pair(0, 0)));

    auto insert = [&](int u, int v, int x)
    {
        E[u].emplace_back(v, x);
        if (lazy(v)) big[u].emplace_back(v, x);
    };

    vector cnt(n, 0), on(n, 0);

    auto update_status = [&](int u, int x)
    {
        on[u] += x;
        for (auto [v, y] : big[u]) cnt[v] += x * y;
    };

    auto update_friendship = [&](int u, int v, int x)
    {
        if (lazy(u)) cnt[u] += x * on[v];
        auto iterE = lower_bound(all(E[u]), pair(v, 0));
        iterE->second += x;
        if (not lazy(v)) return;
        auto iterbig = lower_bound(all(big[u]), pair(v, 0));
        iterbig->second += x;
    };

    auto count_online = [&](int u)
    {
        if (lazy(u)) return cnt[u];
        int res = 0;
        for (auto [v, y] : E[u]) res += on[v] * y;
        return res;
    };

    vector queries(q, tuple('a', 0, -1));

    for (auto& [t, u, v] : queries)
    {
        cin >> t >> u; --u;
        if (t == 'A' || t == 'D') { cin >> v; --v; }
        if (t == 'A')
        {
            if (u > v) swap(u, v);
            edges.emplace_back(u, v, INF);
        }
    }

    sort(all(edges));
    auto pred = [](auto a, auto b) { return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b); };
    edges.erase(unique(all(edges), pred), end(edges));

    for (auto& [u, v, x] : edges)
    {
        if (x == INF) x = 0;
        deg[u] += 1, deg[v] += 1;
    }

    M = accumulate(all(deg), 0);

    for (auto& [u, v, x] : edges) insert(u, v, x), insert(v, u, x);

    for (int u = 0; u < n; ++u) sort(all(E[u])), sort(all(big[u]));

    for (auto u : initial) update_status(u, 1);

    for (auto [t, u, v] : queries)
    {
        if (t == 'O') update_status(u, 1);
        if (t == 'F') update_status(u, -1);

        if (t == 'A') update_friendship(u, v, 1), update_friendship(v, u, 1);
        if (t == 'D') update_friendship(u, v, -1), update_friendship(v, u, -1);

        if (t == 'C') cout << count_online(u) << endl;
    }

    exit(0);
}