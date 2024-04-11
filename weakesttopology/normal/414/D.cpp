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
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> cnt(n);

    auto dfs = [&](auto& self, int u, int p, int h) -> void
    {
        cnt[h] += 1;
        for (auto v : E[u]) if (v != p) self(self, v, u, h + 1);
    };
    dfs(dfs, 0, -1, 0);

    vector<ll> sum(n), wsum(n);
    for (int i = 0; i < n; ++i)
    {
        sum[i] = cnt[i];
        wsum[i] = 1LL * i * cnt[i];
        if (i > 0)
        {
            sum[i] += sum[i - 1];
            wsum[i] += wsum[i - 1];
        }
    }
    auto query = [&](const auto& v, int l, int r) -> ll
    {
        if (r < l) return 0;
        return v[r] - (l ? v[l - 1] : 0LL);
    };

    ll res = 0;

    for (int h = 1; h < n; ++h)
    {
        auto check = [&](int x)
        {
            ll left = query(sum, x, h - 1);
            return query(sum, x, h) <= k && left * h - query(wsum, x, h - 1) <= p;
        };

        int x = h + 1;
        for (int z = x; z > 0; z >>= 1) while (z < x && check(x - z)) x -= z;

        ll cur = query(sum, x, h);
        if (x > 1)
        {
            ll coins_left = p - (query(sum, x, h - 1) * h - query(wsum, x, h - 1));
            cur += min<ll>({k - cur, x == h + 1 ? INF : coins_left / (h - (x - 1)), cnt[x - 1]});
        }

        res = max(res, cur);
    }

    cout << res << endl;

    exit(0);
}