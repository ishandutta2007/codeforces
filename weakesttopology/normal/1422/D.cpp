#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll dist(auto p, auto q)
{
    return abs(p.first - q.first) + abs(p.second - q.second);
}

bool chmin(auto& x, auto y)
{
    return y < x ? x = y, true : false;
}

int main()
{ _
    int n, m; cin >> n >> m;

    using ii = pair<ll, ll>;

    ii s, f;
    cin >> s.first >> s.second;
    cin >> f.first >> f.second;

    vector x(m, 0LL), y(m, 0LL);

    vector<ii> p(m);
    for (int j = 0; j < m; ++j)
    {
        cin >> x[j] >> y[j];
        p[j] = { x[j], y[j] };
    }

    x.push_back(s.first);
    y.push_back(s.second);

    sort(all(x)), x.erase(unique(all(x)), end(x));
    sort(all(y)), y.erase(unique(all(y)), end(y));

    int N = sz(x), M = sz(y);

    int src = m + N + M, snk = m + N + M + 1;

    vector E(m + N + M + 2, vector(0, pair(0, 0LL)));

    for (int z = 0; z + 1 < sz(x); ++z)
    {
        E[m + z].emplace_back(m + z + 1, x[z + 1] - x[z]);
        E[m + z + 1].emplace_back(m + z, x[z + 1] - x[z]);
    }

    for (int z = 0; z + 1 < sz(y); ++z)
    {
        E[m + N + z].emplace_back(m + N + z + 1, y[z + 1] - y[z]);
        E[m + N + z + 1].emplace_back(m + N + z, y[z + 1] - y[z]);
    }

    for (int j = 0; j < m; ++j)
    {
        auto iterx = lower_bound(all(x), p[j].first);
        int idx = (int)distance(begin(x), iterx);
        E[j].emplace_back(m + idx, 0LL);
        E[m + idx].emplace_back(j, 0LL);

        auto itery = lower_bound(all(y), p[j].second);
        int idy = (int)distance(begin(y), itery);
        E[j].emplace_back(m + N + idy, 0LL);
        E[m + N + idy].emplace_back(j, 0LL);
    }

    {
        auto iterx = lower_bound(all(x), s.first);
        int idx = (int)distance(begin(x), iterx);
        E[src].emplace_back(m + idx, 0LL);

        auto itery = lower_bound(all(y), s.second);
        int idy = (int)distance(begin(y), itery);
        E[src].emplace_back(m + N + idy, 0LL);
    }

    for (int j = 0; j < m; ++j)
    {
        E[src].emplace_back(j, dist(s, p[j]));
        E[j].emplace_back(snk, dist(f, p[j]));
    }

    E[src].emplace_back(snk, dist(s, f));

    auto dijkstra = [&](int s, auto& E)
    {
        int n = sz(E);
        vector dist(n, LINF); dist[s] = 0LL;
        priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(pair(0LL, s));
        while (!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : E[u])
                if (chmin(dist[v], dist[u] + w))
                    pq.push(pair(dist[v], v));
        }
        return dist;
    };

    auto d = dijkstra(src, E);

    // for (int j = 0; j < m; ++j) debug(d[j]);

    ll ans = d[snk];

    cout << ans << endl;

    exit(0);
}