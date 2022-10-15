#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, m; cin >> n >> m;

    vector E(n, vector(0, 0));

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        if (u != v) E[u].push_back(v);
    }

    auto bfs = [&](int s)
    {
        vector dist(n, -1); dist[s] = 0;

        queue<int> q; q.push(s);

        while (not empty(q))
        {
            int u = q.front(); q.pop();
            for (auto v : E[u]) if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        return dist;
    };

    vector dist(n, vector(0, 0));

    for (int u = 0; u < n; ++u)
    {
        dist[u] = bfs(u);
        dist[u][u] = -1;
    }

    vector bestin(n, vector(n, pair(0, 0))), bestout(n, vector(n, pair(0, 0)));

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            bestin[u][v] = pair(dist[v][u], v);
            bestout[u][v] = pair(dist[u][v], v);
        }
        sort(rall(bestin[u])), sort(rall(bestout[u]));
    }

    int ans = 0;

    array<int, 4> tour;

    auto update = [&](array<int, 4> trip)
    {
        auto temp = trip;
        sort(all(temp));
        for (int i = 1; i < 4; ++i) if (temp[i] == temp[i - 1]) return;

        int cost = 0;
        for (int i = 1; i < 4; ++i)
        {
            int u = trip[i - 1], v = trip[i];
            if (dist[u][v] == -1) return;
            cost += dist[u][v];
        }

        if (ans < cost) ans = cost, tour = trip;
    };

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v) if (dist[u][v] != -1)
        {
            for (int i = 0; i < min(n, 3); ++i)
                for (int j = 0; j < min(n, 3); ++j)
                {
                    int w = bestin[u][i].second;
                    int z = bestout[v][j].second;

                    array<int, 4> trip = { w, u, v, z };
                    update(trip);
                }
        }

    for (auto u : tour) cout << u + 1 << " ";
    cout << endl;

    exit(0);
}