#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;
    vector a(n, 0LL);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a[i] -= (i + 1);

    auto chmax = [](auto& x, auto y) { x = max(x, y); };
    vector dp(n + 1, vector(n + 1, -LINF));
    dp[0][0] = 0;

    auto valid = [&n](int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; };

    for (int i = 1; i < n + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            for (int t = -1; t <= 1; ++t)
            {
                if (not valid(i - 1, j + t)) continue;
                if (dp[i - 1][j + t] == -LINF) continue;
                chmax(dp[i][j], dp[i - 1][j + t] - t * a[i - 1]);
            }

    ll ans = dp[n][0];

    cout << ans << endl;

    exit(0);
}