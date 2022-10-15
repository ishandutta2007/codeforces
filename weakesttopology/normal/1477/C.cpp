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

ll sq(ll x) { return x * x; }

int main()
{ _
    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    for (int u = 0; u < n; ++u) cin >> x[u] >> y[u];

    auto dist = [&](int u, int v){ return sq(x[u] - x[v]) + sq(y[u] - y[v]); };

    vector<int> p(n, 0), vis(n, 0);

    vis[0] = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int v = p[i];
        for (int u = 0; u < n; ++u)
        {
            if (not vis[u] && dist(p[i], u) > dist(p[i], v)) v = u;
        }
        p[i + 1] = v, vis[v] = 1;
    }

    for (int i = 0; i < n; ++i) cout << p[i] + 1 << "\n "[i + 1 < n];

    exit(0);
}