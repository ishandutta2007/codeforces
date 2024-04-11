#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int solve()
{
    int n; cin >> n;
    vector a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1) return a[0];

    auto chmin = [](int& x, int y) { x = min(x, y); };

    vector dp(2, vector(n, INF));
    dp[0][0] = dp[1][1] = a[0];
    dp[0][1] = a[0] + a[1];

    for (int i = 2; i < n; ++i)
    {
        for (int b = 0; b < 2; ++b)
        {
            chmin(dp[b][i], dp[!b][i - 1] + (!b && a[i]));
            chmin(dp[b][i], dp[!b][i - 2] + (!b) * (a[i] + a[i - 1]));
        }
    }

    int ans = min(dp[0][n - 1], dp[1][n - 1]);

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}