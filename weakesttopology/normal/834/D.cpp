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

bool chmax(auto& x, auto y) { return x < y ? x = y, true : false; }

int main()
{ _
    int n, k; cin >> n >> k;

    vector a(n, 0);

    for (auto& x : a) { cin >> x; --x; }

    vector ct(n, 0);

    int lcur = 0, rcur = 0, cost = 0;

    auto insert = [&](int i) { if (ct[a[i]]++ == 0) ++cost; };
    auto remove = [&](int i) { if (--ct[a[i]] == 0) --cost; };

    insert(0);

    auto C = [&](int l, int r)
    {
        while (l < lcur) insert(--lcur);
        while (rcur < r) insert(++rcur);
        while (lcur < l) remove(lcur++);
        while (r < rcur) remove(rcur--);
        return cost;
    };

    vector dp(2, vector(n, 0));

    int b = 0;

    function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr)
    {
        if (r < l) return;

        int m = l + (r - l) / 2, opt = -1;

        for (int x = optl; x <= min(m, optr); ++x)
            if(chmax(dp[b ^ 1][m], (x ? dp[b][x - 1] : 0) + C(x, m))) opt = x;

        solve(l, m - 1, optl, opt), solve(m + 1, r, opt, optr);
    };

    for (int j = 0; j < k; ++j, b ^= 1)
    {
        solve(0, n - 1, 0, n - 1);
        fill(all(dp[b]), 0);
    }

    int ans = dp[b][n - 1];

    cout << ans << endl;

    exit(0);
}