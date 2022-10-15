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

    vector v(n, 0);

    for (auto& x : v) cin >> x;

    sort(all(v));

    vector dp(n, 0);

    auto query = [&](int l, int r)
    {
        if (l <= 0) return dp[r];
        else return dp[r] - dp[l - 1];
    };

    auto check = [&](int x)
    {
        fill(all(dp), 0);

        if (v[k - 1] - v[0] > x) return false;

        dp[k - 1] = 1;

        for (int i = k; i < n; ++i)
        {
            int j = (int)distance(begin(v), lower_bound(all(v), v[i] - x));

            dp[i] = dp[i - 1];

            if (j > 0 && (j - 1 > i - k || not query(j - 1, i - k))) continue;

            dp[i] += 1;
        }

        return query(n - 1, n - 1) > 0;
    };

    int ans = -1;

    for (int z = 1e9; z > 0; z >>= 1)
        while (not check(ans + z)) ans += z;

    ans += 1;

    cout << ans << endl;

    check(10);

    exit(0);
}