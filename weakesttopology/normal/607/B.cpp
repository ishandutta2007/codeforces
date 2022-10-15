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

constexpr int nmax = 500;
int dp[nmax][nmax];

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

int main()
{ _
    int n; cin >> n;

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
        if (i + 1 < n) dp[i][i + 1] = (c[i] == c[i + 1] ? 1 : 2);
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int l = 0; l + len <= n; ++l)
        {
            int r = l + len - 1;
            dp[l][r] = len;
            for (int i = l; i <= r; ++i)
            {
                if (c[i] != c[l]) continue;
                int left = i > l + 1 ? dp[l + 1][i - 1] : dp[l][i];
                int right = i < r ? dp[i + 1][r] : 0;
                chmin(dp[l][r], left + right);
            }
        }
    }

    int ans = dp[0][n - 1];

    cout << ans << endl;

    exit(0);
}