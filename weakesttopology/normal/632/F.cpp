#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmin(auto& x, auto y) { return y < x ? x = y, true : false; }

void fail()
{
    cout << "NOT MAGIC" << endl;
    exit(0);
}

int main()
{ _
    int n; cin >> n;

    vector A(n, vector(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (A[i][j] != A[j][i])
                fail();
        if (A[i][i]) fail();
    }

    struct Data
    {
        int key, v, p;
        Data(int key, int v, int p) : key(key), v(v), p(p) { }
        bool operator<(const Data& rhs) const { return key > rhs.key; }
    };

    priority_queue<Data> pq; pq.emplace(0, 0, 0);

    vector E(n, vector(0, pair(0, 0)));
    vector vis(n, 0);

    while (not pq.empty())
    {
        auto [key, u, p] = pq.top(); pq.pop();
        if (vis[u]++) continue;
        if (u != p) E[u].emplace_back(p, A[u][p]), E[p].emplace_back(u, A[u][p]);
        for (int v = 0; v < n; ++v) if (not vis[v])
            pq.emplace(A[u][v], v, u);
    }

    auto dijkstra = [&](int s)
    {
        vector dist(n, INF); dist[s] = 0;
        priority_queue<Data> pq; pq.emplace(0, s, -1);
        while (!pq.empty())
        {
            auto [d, u, p] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : E[u])
                if (chmin(dist[v], max(dist[u], w)))
                    pq.emplace(dist[v], v, u);
        }
        return dist;
    };

    for (int u = 0; u < n; ++u)
    {
        auto dist = dijkstra(u);
        for (int v = 0; v < n; ++v) if (A[u][v] > dist[v]) fail();
    }

    cout << "MAGIC" << endl;

    exit(0);
}