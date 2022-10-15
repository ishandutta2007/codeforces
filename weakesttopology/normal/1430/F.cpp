#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmin(auto& x, auto y) { return y < x ? x = y, true : false; }

int main()
{ _
    int n, k; cin >> n >> k;

    vector l(n + 1, INF), r(n + 1, INF), a(n + 1, 0);

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i] >> a[i];

    vector waste(n, vector(n, -1)), slack(n, vector(n, 0));

    for (int i = 0; i < n; ++i)
    {
        int rem = k;
        for (int j = i; j < n; ++j)
        {
            int reloads = (max(0, a[j] - rem) + (k - 1)) / k;
            int cut = l[j] + reloads;
            if (cut > r[j]) break;
            if (cut < l[j + 1]) slack[i][j] = 1;
            waste[i][j] = rem = rem - a[j] + k * reloads;
        }
    }

    vector dp(n + 1, LINF); dp[0] = 0LL;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j) if (slack[i][j] && waste[i][j] != -1)
            chmin(dp[j + 1], dp[i] + waste[i][j]);

        if (waste[i][n - 1] != -1) chmin(dp[n], dp[i]);
    }

    ll ans = dp.back() == LINF ? -1 : accumulate(all(a), 0LL) + dp.back();

    cout << ans << endl;

    exit(0);
}