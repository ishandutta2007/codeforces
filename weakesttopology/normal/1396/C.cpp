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

bool chmin(auto& x, auto y) { return y < x ? x = y, true : false; }

int main()
{ _
    int n; cin >> n;

    ll r[3];

    for (int t = 0; t < 3; ++t) cin >> r[t];

    ll d; cin >> d;

    vector a(n, 0LL);

    for (auto& x : a) cin >> x;

    vector dp(n, LINF);

    for (int i = 0; i < n; ++i)
    {
        // kill and go
        {
            ll add = i > 0 ? dp[i - 1] + d : 0LL;

            chmin(dp[i], add + r[0] * a[i] + r[2]);
            chmin(dp[i], add + r[0] * (a[i] + 2) + 2 * d);
            chmin(dp[i], add + r[1] + r[0] + 2 * d);
        }
        // kill and come back
        if (i > 0)
        {
            ll add = (i > 1 ? dp[i - 2] + d : 0LL) + 2 * d;

            ll cur = min(r[1], (a[i] + 1) * r[0]) + d + r[0];

            if (i == n - 1) cur = min(cur, a[i] * r[0] + r[2]);

            ll prv = min(r[1], (a[i - 1] + 1) * r[0]) + r[0];

            chmin(dp[i], add + cur + prv);
        }
    }

    ll ans = dp[n - 1];

    cout << ans << endl;

    exit(0);
}