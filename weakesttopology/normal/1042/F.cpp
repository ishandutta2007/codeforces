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
    int n, k; cin >> n >> k;

    vector<vector<int>> E(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;
    }

    int root = 0;
    while (deg[root] == 1) ++root;

    vector<int> h(n, 0);

    int ans = 1;

    auto solve = [&](auto& self, int u, int p) -> int
    {
        if (deg[u] == 1) return h[u];

        int mx = -1;

        for (auto v : E[u]) if (v != p)
        {
            h[v] = h[u] + 1;

            int d = self(self, v, u);

            if (mx == -1) mx = d;
            else
            {
                if (mx + d - 2 * h[u] <= k) mx = max(mx,  d);
                else
                {
                    ans += 1;
                    mx = min(mx, d);
                }
            }
        }

        return mx;
    };

    solve(solve, root, -1);

    cout << ans << endl;

    exit(0);
}