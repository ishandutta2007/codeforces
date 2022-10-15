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
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        for (int t = 0; t < 2; ++t)
        {
            int w = j + 1, last = u;
            while (w >= 10)
            {
                int N = size(E);
                E.emplace_back();
                E[N].emplace_back(last, w % 10);
                w /= 10;
                last = N;
            }
            E[v].emplace_back(last, w);

            swap(u, v);
        }
    }

    int N = size(E);

    vector<int> vis(N, 0);
    queue<pair<vector<int>, ll>> q;

    q.emplace(vector<int>(1, 0), 0LL);

    const ll mod = 1e9 + 7;

    vector<ll> ans(N);

    while (not empty(q))
    {
        auto [block, dist] = q.front();
        q.pop();

        vector<vector<int>> nxt(10);

        for (auto u : block) if (not vis[u])
        {
            vis[u] = 1, ans[u] = dist;
            for (auto [v, w] : E[u]) if (not vis[v])
            {
                nxt[w].push_back(v);
            }
        }

        for (int d = 0; d < 10; ++d) if (not empty(nxt[d]))
        {
            q.emplace(move(nxt[d]), (10 * dist + d) % mod);
        }
    }

    for (int u = 1; u < n; ++u)
    {
        cout << ans[u] << endl;
    }

    exit(0);
}