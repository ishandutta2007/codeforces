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

ll solve()
{
    int n, m; cin >> n >> m;

    vector a(n, vector(m, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if (c == '*') a[i][j] = 1;
        }

    vector dp(n, vector(m, 0));

    dp[n - 1] = a[n - 1];

    for (int i = 0; i < n; ++i)
        dp[i][0] = a[i][0], dp[i][m - 1] = a[i][m - 1];

    for (int i = n - 2; i >= 0; --i)
        for (int j = 1; j < m - 1; ++j) if (a[i][j])
        {
            pair<int, int> children[3] = {
                { i + 1, j - 1 },
                { i + 1, j },
                { i + 1, j + 1 }
            };

            dp[i][j] = INF;

            for (auto [ ii, jj ] : children)
                dp[i][j] = min(dp[i][j], 1 + dp[ii][jj]);
        }

    ll ans = 0LL;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += dp[i][j];

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}