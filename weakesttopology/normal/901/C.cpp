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

    vector<vector<int>> E(n);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> p(n, -1), h(n, 0), a(n, INF);

    auto add_cycle = [&](int u, int v)
    {
        int L = INF, R = 0;
        while (u != v)
        {
            L = min({ L, u, v });
            R = max({ R, u, v });
            if (h[u] >= h[v]) u = p[u];
            else v = p[v];
        }
        a[L] = min(a[L], R);
    };

    auto dfs = [&](auto& self, int u) -> void
    {
        for (auto v : E[u])
        {
            if (p[v] == -1)
            {
                p[v] = u, h[v] = h[u] + 1;
                self(self, v);
            }
            else if (v != p[u])
            {
                add_cycle(u, v);
            }
        }
    };
    for (int u = 0; u < n; ++u)
    {
        if (p[u] == -1)
        {
            p[u] = u;
            dfs(dfs, u);
        }
    }

    for (int u = n - 2; u >= 0; --u)
    {
        a[u] = min(a[u], a[u + 1]);
    }

    vector<ll> prefix_sum(n, 0);

    for (int u = 0; u < n; ++u) if (a[u] < INF)
    {
        prefix_sum[u] = a[u] - u;
        if (u > 0) prefix_sum[u] += prefix_sum[u - 1];
    }

    auto query = [&](int l, int r)
    {
        if (r < l) return 0LL;
        return prefix_sum[r] - (l ? prefix_sum[l - 1] : 0LL);
    };

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;

        auto iterL = begin(a) + l, iterR = begin(a) + r + 1;
        auto iter = upper_bound(iterL, iterR, r);
        int i = (int)distance(begin(a), iter);

        ll len = (r - i + 1);
        ll res = query(l, i - 1) + len * (len + 1) / 2;

        cout << res << endl;
    }

    exit(0);
}