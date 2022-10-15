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

constexpr int K = 26, N = 2e5;

array<int, K> ct;
array<int, N + 1> dp;

ll solve()
{
    int n, m, k; cin >> n >> m >> k;

    fill(all(ct), 0);

    string s; cin >> s;

    for (auto c : s) ct[c - 'A'] += 1;


    ll ans = LINF;

    for (int x = 0; x < K; ++x) if (ct[x])
    {
        fill(begin(dp), begin(dp) + n + 1, 0); dp[0] = 1;

        for (int y = 0; y < K; ++y) if (y != x && ct[y])
            for (int p = n; p >= 0; --p)
                if (dp[p] && p + ct[y] <= n) dp[p + ct[y]] = 1;

        for (int p = 0; p <= n; ++p) if (dp[p] && ct[x] + p >= n)
        {
            ll cur = (n - p) * max(0, m - (k - (ct[x] + p)));
            ans = min(ans, cur);
        }
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}