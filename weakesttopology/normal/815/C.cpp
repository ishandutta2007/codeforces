#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll b;
    cin >> b;

    vector<ll> c(n), d(n);
    vector<vector<int>> E(n);

    for (int u = 0; u < n; ++u) {
        cin >> c[u] >> d[u];
        if (u) {
            int p;
            cin >> p;
            --p;
            E[p].push_back(u);
        }
    }

    vector<int> heavy(n, -1);
    auto dfs = [&](auto& self, int u) -> int {
        int w = 1, mx = 0;
        for (auto v : E[u]) {
            int wv = self(self, v);
            if (wv > mx) heavy[u] = v;
            w += wv;
        }
        return w;
    };
    dfs(dfs, 0);

    auto solve = [&](auto&& self, int u) -> array<vector<ll>, 2> {
        vector<ll> dp = { 0, c[u] - d[u] }, values = { c[u] };

        if (int v = heavy[u]; v != -1) {
            auto [dpv, valuesv] = self(self, v);
            for (auto& x : dpv) x += c[u] - d[u];
            dpv.insert(begin(dpv), 0);
            swap(dp, dpv), swap(values, valuesv);
            values.push_back(c[u]);
            inplace_merge(all(values) - 1, end(values));
        }

        for (auto v : E[u]) if (v != heavy[u]) {
            auto [add, add_values] = self(self, v);
            int k = (int)size(dp), l = (int)size(add);
            for (int y = 1; y < l; ++y) dp.push_back(dp[k - 1] + add[y]);
            for (int x = k - 1; x >= 1; --x) {
                for (int y = 1; y < l; ++y)
                    dp[x + y] = min(dp[x + y], dp[x] + add[y]);
            }
            vector<ll> nvalues;
            merge(all(values), all(add_values), back_inserter(nvalues));
            swap(values, nvalues);
        }

        ll sum = 0;
        for (int i = 0; i < (int)size(values); ++i) {
            sum += values[i];
            dp[i + 1] = min(dp[i + 1], sum);
        }

        return {dp, values};
    };

    auto [dp, values] = solve(solve, 0);

    auto iter = upper_bound(all(dp), b);
    int res = (int)distance(begin(dp), iter) - 1;

    cout << res << endl;

    exit(0);
}