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

void fail()
{
    cout << -1 << endl;
    exit(0);
}

vector<int> bfs(int s, const auto& E)
{
    vector<int> dist(size(E), INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (not empty(q))
    {
        int u = q.front(); q.pop();
        for (auto v : E[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main()
{ _
    int n, k; cin >> n >> k;

    if (k == 1 || k > 3) fail();

    vector<pair<int, int>> edges;

    if (n <= 6)
    {
        int m = n * (n - 1) / 2;

        for (int mask = 0; mask < (1 << m); ++mask)
        {
            vector<vector<int>> E(n), F(n);
            for (int u = 0, ptr = 0; u < n; ++u)
                for (int v = u + 1; v < n; ++v, ++ptr)
                {
                    if (mask >> ptr & 1)
                    {
                        E[u].push_back(v), E[v].push_back(u);
                    }
                    else
                    {
                        F[u].push_back(v), F[v].push_back(u);
                    }
                }

            int diamE = 0, diamF = 0;

            for (int u = 0; u < n; ++u)
            {
                auto distE = bfs(u, E), distF = bfs(u, F);
                diamE = max(diamE, *max_element(all(distE)));
                diamF = max(diamF, *max_element(all(distF)));
            }

            if (min(diamE, diamF) == k && max(diamE, diamF) < INF)
            {
                for (int u = 0, ptr = 0; u < n; ++u)
                    for (int v = u + 1; v < n; ++v, ++ptr)
                    {
                        if (mask >> ptr & 1) edges.emplace_back(u + 1, v + 1);
                    }
                break;
            }
        }

        if (empty(edges)) fail();
    }
    else if (k == 3)
    {
        for (int u = 1; u <= n - 2; ++u)
            for (int v = u + 1; v <= n - 2; ++v)
                edges.emplace_back(u, v);

        edges.emplace_back(n - 1, 1);
        edges.emplace_back(n - 1, n);
    }
    else
    {
        for (int u = 1; u <= n - 1; ++u)
            edges.emplace_back(u, u + 1);
    }

    cout << size(edges) << endl;
    for (auto [u, v] : edges) cout << u << " " << v << endl;

    exit(0);
}