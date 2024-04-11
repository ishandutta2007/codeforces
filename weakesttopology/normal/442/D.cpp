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
    int n; cin >> n;

    n += 1;

    vector p(n, -1);

    for (int u = 1; u < n; ++u)
    {
        cin >> p[u]; --p[u];
    }

    vector heavy(n, pair(n, n));
    vector cost(n + 1, 0); cost[n] = -1;

    auto fix = [&](int u)
    {
        auto& [a, b] = heavy[u];
        if (cost[a] < cost[b]) swap(a, b);
        return cost[u] = max(cost[a], cost[b] + 1);
    };

    auto update = [&](int u, int v)
    {
        auto& [a, b] = heavy[u];

        if ((b != -1 && cost[v] <= cost[b]) || v == heavy[u].first)
            return cost[u] != fix(u);

        b = v;

        return cost[u] != fix(u);
    };

    int ans = 1;

    for (int u = 1; u < n; ++u)
    {
        cost[u] = 1;

        for (int v = u; p[v] != 0 && update(p[v], v); v = p[v])
            ans = max(ans, cost[p[v]]);

        cout << ans << endl;;
    }

    exit(0);
}