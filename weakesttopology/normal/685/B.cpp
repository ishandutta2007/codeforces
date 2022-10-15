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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> E(n);
    vector<int> p(n, -1);

    for (int u = 1; u < n; ++u)
    {
        cin >> p[u];
        --p[u];
        E[p[u]].push_back(u);
    }

    vector<int> w(n, 0), c(n, 0), heavy(n, -1);
    iota(all(c), 0);

    auto solve = [&](auto& self, int u) -> void
    {
        w[u] = 1;
        for (auto v : E[u])
        {
            self(self, v);
            w[u] += w[v];
            if (heavy[u] == -1 || w[heavy[u]] < w[v]) heavy[u] = v;
        }
        if (heavy[u] != -1 && 2 * w[heavy[u]] > w[u])
        {
            int x = c[heavy[u]];
            while (2 * w[x] <= w[u]) x = p[x];
            c[u] = x;
        }
    };
    solve(solve, 0);

    for (int z = 0; z < q; ++z)
    {
        int v;
        cin >> v;
        --v;
        cout << c[v] + 1 << endl;
    }

    exit(0);
}