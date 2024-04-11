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

    vector a(n, vector(0, 0LL));

    for (auto& v : a)
    {
        int t; cin >> t;

        v.resize(t);

        for (auto& x : v) cin >> x;

        partial_sum(all(v), begin(v));

        v.resize(min(t, k));
    }

    vector sum(n, 0LL);

    for (int i = 0; i < n; ++i) sum[i] = a[i].back();

    ll ans = 0LL;

    vector dp(k + 1, 0LL);

    stack<pair<ll&, ll>> stk;

    auto chmax = [&](ll& x, ll y)
    {
        if (x >= y) return false;
        stk.emplace(x, x);
        x = y;
        return true;
    };

    auto update = [&](int l, int r)
    {
        int num = 0;

        for (int j = l; j <= r; ++j)
            for (int z = k - 1; z >= 0; --z)
                if (int x = z + size(a[j]); x <= k)
                    num += chmax(dp[x], dp[z] + sum[j]);

        return num;
    };

    auto clean = [&](int num)
    {
        for (int i = 0; i < num; ++i)
        {
            stk.top().first = stk.top().second;
            stk.pop();
        }
    };

    function<void(int, int)> solve = [&](int l, int r)
    {
        if (l == r)
        {
            ans = max(ans, dp[k]);
            for (int j = 0; j < min(k, size(a[l])); ++j)
                ans = max(ans, a[l][j] + dp[k - (j + 1)]);
        }
        else
        {
            int m = l + (r - l) / 2;

            {
                int num = update(m + 1, r);
                solve(l, m);
                clean(num);
            }

            {
                int num = update(l, m);
                solve(m + 1, r);
                clean(num);
            }
        }
    };

    solve(0, n - 1);

    cout << ans << endl;

    exit(0);
}