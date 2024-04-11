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

void fail(string s = "")
{
    debug(s);
    cout << 0 << endl;
    exit(0);
}

int main()
{ _
    int n; cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    {
        auto values = a;
        sort(all(values)), values.erase(unique(all(values)), end(values));
        for (auto& x : a)
        {
            auto iter = lower_bound(all(values), x);
            x = (int)distance(begin(values), iter);
        }
    }

    vector<vector<int>> cl(n);

    for (int u = 0; u < n; ++u) cl[a[u]].push_back(u);

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> L(n, -1), R(n);
    int timer = 0;

    function<void(int)> tour = [&](int u)
    {
        L[u] = timer;
        for (auto v : E[u]) if (L[v] == -1) tour(v);
        R[u] = timer++;
    };
    tour(0);

    vector<int> bad(n + 1, 0);

    auto update = [&](int l, int r, int x)
    {
        bad[l] += x, bad[r + 1] -= x;
    };

    for (int x = 0; x < n; ++x) if (size(cl[x]) > 1)
    {
        set<int> active;
        for (auto u : cl[x]) active.insert(R[u]);

        int lca = -1;

        for (auto u : cl[x])
        {
            auto iterl = active.lower_bound(L[u]);
            auto iterr = active.upper_bound(R[u]);

            if (next(iterl) != iterr)
            {
                if (lca != -1 || iterl != begin(active) || iterr != end(active))
                    fail("two lcas, u == " + to_string(u + 1));
                lca = u;
            }
        }

        if (lca == -1)
        {
            for (auto u : cl[x]) update(L[u], R[u], 1);
        }
        else
        {
            update(0, n - 1, +1);

            bool found = false;

            for (auto v : E[lca]) if (L[lca] <= L[v] && R[v] <= R[lca])
            {
                auto iterl = active.lower_bound(L[v]);
                auto iterr = active.upper_bound(R[v]);

                if (iterl != iterr)
                {
                    if (found) fail("two children, v == " + to_string(v));
                    found = true;

                    update(L[v], R[v], -1);
                }
            }

            for (auto u : cl[x]) if (u != lca) update(L[u], R[u], +1);
        }
    }

    for (int i = 1; i < n; ++i) bad[i] += bad[i - 1];

    int ans = 0;

    for (int u = 0; u < n; ++u)
    {
        ans += not bad[R[u]];
    }

    cout << ans << endl;

    exit(0);
}