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
    int n;
    cin >> n;

    vector<double> p(n);
    for (auto& x : p)
    {
        cin >> x;
        x = 1 - x;
    }

    vector<vector<int>> E(n);
    vector<int> deg(n, 0);

    double ans = accumulate(all(p), 0.0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;

        ans -= p[u] * p[v];
    }

    const int magic = (int)sqrt(n) + 1;

    vector<vector<int>> heavy(n);
    vector<double> sum_light(n, 0);

    for (int u = 0; u < n; ++u)
    {
        for (auto v : E[u])
        {
            if (deg[u] > magic)
            {
                heavy[v].push_back(u);
            }
            else
            {
                sum_light[v] += p[u];
            }
        }
    }

    debug(ans);

    int q;
    cin >> q;

    cout << setprecision(10) << fixed;

    for (int z = 0; z < q; ++z)
    {
        int u;
        cin >> u;
        double q;
        cin >> q;
        q = 1 - q;

        double delta = q - p[u];

        if (deg[u] <= magic)
        {
            for (auto v : E[u])
            {
                ans -= delta * p[v];
                sum_light[v] += delta;
            }
        }
        else
        {
            ans -= delta * sum_light[u];
            for (auto v : heavy[u])
            {
                ans -= delta * p[v];
                sum_light[v] += delta;
            }
        }
        ans += delta;
        p[u] = q;

        cout << ans << endl;
    }

    exit(0);
}