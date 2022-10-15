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

const int nmax = 30, kmax = 50;

ll dp[nmax + 1][nmax + 1][kmax + 1];

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

int main()
{ _
    for (int n = 0; n <= nmax; ++n)
        for (int m = 0; m <= nmax; ++m)
        {
            for (int k = 1; k <= kmax; ++k) dp[n][m][k] = LINF;
            if (n * m <= kmax) dp[n][m][n * m] = 0LL;
        }

    for (int n = 1; n <= nmax; ++n)
        for (int m = 1; m <= nmax; ++m)
            for (int k = 1; k <= min(kmax, n * m); ++k)
            {
                for (int x = 1; x < n; ++x)
                    for (int j = 1; j <= k; ++j)
                        chmin(dp[n][m][k], dp[x][m][j] + dp[n - x][m][k - j] + m * m);

                for (int y = 1; y < m; ++y)
                    for (int j = 1; j <= k; ++j)
                        chmin(dp[n][m][k], dp[n][y][j] + dp[n][m - y][k - j] + n * n);
            }

    int t; cin >> t;

    while (t--)
    {
        int n, m, k; cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }

    exit(0);
}