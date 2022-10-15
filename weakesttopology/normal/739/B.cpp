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

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<pair<int, int>>> E(n);

    for (int u = 1; u < n; ++u)
    {
        int p, w;
        cin >> p >> w;
        --p;
        E[p].emplace_back(u, w);
    }

    vector<int> res(n, 0), stk;
    vector<ll> h(n);

    auto solve = [&](auto& self, int u) -> void
    {
        int k = -1;
        for (int z = size(stk); z > 0; z >>= 1)
            while (k + z < size(stk) && h[stk[k + z]] < h[u] - a[u]) k += z;

        if (k >= 0) res[stk[k]] -= 1;
        if (not empty(stk)) res[stk.back()] += 1;

        stk.push_back(u);
        for (auto [v, w] : E[u])
        {
            h[v] = h[u] + w;
            self(self, v);
        }
        stk.pop_back();
        if (not empty(stk)) res[stk.back()] += res[u];
    };
    solve(solve, 0);

    for (int u = 0; u < n; ++u)
    {
        cout << res[u] << "\n "[u + 1 < n];
    }


    exit(0);
}