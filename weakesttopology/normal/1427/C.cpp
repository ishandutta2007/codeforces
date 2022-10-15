#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
int size(const auto& X) { return (int)std::size(X); }

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmax(auto& x, auto y)
{
    return x < y ? x = y, true : false;
}

int main()
{ _
    int r, n; cin >> r >> n;

    vector t(n + 1, 0), x(n + 1, 0), y(n + 1, 0); x[0] = y[0] = 1;

    for (int i = 1; i <= n; ++i) cin >> t[i] >> x[i] >> y[i];

    auto dist = [&](int i, int j)
    {
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    };

    vector prefixmax(n + 1, 0), dp(n + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (dist(0, i) <= t[i])
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (t[j] + 1000 > t[i] && t[j] + dist(i, j) <= t[i])
                    chmax(dp[i], 1 + dp[j]);

                if (t[j] + 1000 <= t[i])
                {
                    chmax(dp[i], 1 + prefixmax[j]);
                    break;
                }
            }
        }

        prefixmax[i] = max(prefixmax[i - 1], dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    exit(0);
}