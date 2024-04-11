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

    vector l(n, 0), r(n, 0);

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    vector edges(0, pair(0, 0));

    for (int u = 0; u < n; ++u)
        for (int v = u + 1; v < n; ++v)
            edges.emplace_back(u, v);

    int N = max(*max_element(all(l)), *max_element(all(r))), M = size(edges);

    vector sgn(1 << M, 0);

    for (int mask = 1; mask < (1 << M); ++mask)
        sgn[mask] = __builtin_popcount(mask) % 2 == 1 ? 1 : -1;

    double ans = 0.0;

    vector vis(n, 0);

    vector prob(n, 0.0);

    for (int k = 1; k <= N; ++k)
    {
        for (int u = 0; u < n; ++u)
            prob[u] = double(max(0, r[u] - max(k, l[u]) + 1)) / double(r[u] - l[u] + 1);

        for (int mask = 1; mask < (1 << M); ++mask)
        {
            fill(all(vis), 0);

            for (int j = 0, temp = mask; temp; temp >>= 1, ++j)
                if (temp & 1)
                {
                    auto [u, v] = edges[j];
                    vis[u] = vis[v] = 1;
                }

            double cur = 1.0;

            for (int u = 0; u < n; ++u) if (vis[u])
                cur *= prob[u];

            ans += sgn[mask] * cur;
        }
    }

    cout << setprecision(20) << fixed;

    cout << ans << endl;

    exit(0);
}