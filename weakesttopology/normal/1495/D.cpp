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
    constexpr ll mod = 998244353;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<vector<int>> d;

    for (int u = 0; u < n; ++u)
    {
        vector<int> dist(n, -1);

        queue<int> q;
        q.push(u);
        dist[u] = 0;

        while (not empty(q))
        {
            int v = q.front();
            q.pop();
            for (auto w : E[v]) if (dist[w] == -1)
            {
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }

        d.push_back(dist);
    }

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            vector<int> cnt(n, 0);
            ll res = 1;
            for (int w = 0; w < n; ++w)
            {
                if (d[u][w] + d[w][v] == d[u][v]) cnt[d[u][w]] += 1;
                else
                {
                    int p = 0;
                    for (auto z : E[w])
                    {
                        p += (d[z][u] + 1 == d[w][u]) && (d[z][v] + 1 == d[w][v]);
                    }
                    res = res * p % mod;
                }
            }
            if (*max_element(all(cnt)) > 1) res = 0;
            cout << res << "\n "[v + 1 < n];
        }
    }

    exit(0);
}