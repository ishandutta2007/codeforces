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

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> weight(n), dead(n, 0);
    int rt = -1;

    auto find_centroid = [&](auto& self, int u, int p) -> int
    {
        for (auto v : E[u]) if (v != p && not dead[v])
        {
            if (2 * weight[v] >= weight[rt]) return self(self, v, u);
        }
        return u;
    };

    const ll mod = 1e9 + 7;

    ll sum[2]{}, cnt[2]{}, add[2]{}, addcnt[2]{}, res = 0, cur = 0;

    auto solve = [&](auto& self, int u, int p, int b) -> void
    {
        cur = a[u] - cur;
        cur %= mod;

        res += sum[b] + cur * cnt[b];
        res %= mod;

        add[b] += cur, addcnt[b] += 1;
        add[b] %= mod;

        weight[u] = 1;
        for (auto v : E[u]) if (v != p && not dead[v])
        {
            self(self, v, u, b ^ 1);
            weight[u] += weight[v];
        }

        cur = -cur + a[u];
        cur %= mod;
    };

    queue<int> q;
    q.push(0);

    while (not empty(q))
    {
        int u = q.front();
        q.pop();

        sum[0] = a[u], sum[1] = 0;
        cnt[0] = 1, cnt[1] = 0;
        cur = 0;

        dead[u] = 1;
        for (auto v : E[u]) if (not dead[v])
        {
            solve(solve, v, u, 1);
            for (int t = 0; t < 2; ++t)
            {
                sum[t] += add[t] + (t ? -1 : +1) * a[u] * addcnt[t], add[t] = 0;
                sum[t] %= mod;
                cnt[t] += addcnt[t], addcnt[t] = 0;
            }
            rt = v;
            q.push(find_centroid(find_centroid, v, u));
        }
    }

    debug(res);

    res = (2 * res + accumulate(all(a), 0LL)) % mod;
    res = (res + mod) % mod;

    cout << res << endl;

    exit(0);
}