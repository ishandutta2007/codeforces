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

int main()
{ _
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    vector dp(n + 1, vector(n + 1, vector(n + 1, -INF)));
    dp[0][0][0] = 0;

    auto chmax = [](int& x, int y) { return x < y ? x = y, true : false; };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            for (int x = 0; x < n; ++x)
            {
                int cur = dp[i][j][x];
                if (cur == -INF) continue;

                chmax(dp[i + 1][j + (s[i] != t[0])][x + 1], cur + x * (t[0] == t[1]));
                chmax(dp[i + 1][j + (s[i] != t[1])][x + (t[0] == t[1])], cur + x);
                chmax(dp[i + 1][j][x + (s[i] == t[0])], cur + x * (s[i] == t[1]));
            }

    int ans = 0;
    for (int i = 0; i <= k; ++i)
        for (int x = 0; x <= n; ++x)
            ans = max(ans, dp[n][i][x]);

    cout << ans << endl;

    exit(0);
}