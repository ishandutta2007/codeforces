#include<bits/stdc++.h>

using namespace std;

const int R = (int)3e4 + 5, N = 105;
int n, r, dp[N][R << 1];
pair<int, int> c[N];

bool cmp (pair<int, int> _1, pair<int, int> _2) {
    if ( (_1.second >= 0) != (_2.second >= 0) ) return _1.second >= 0;
    else if (_1.second >= 0) return _1.first < _2.first;
    else return _1.first + _1.second > _2.first + _2.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> r;
    for(int i = 1; i <= n; ++i) cin >> c[i].first >> c[i].second;

    sort(c + 1, c + n + 1, cmp);

    memset(dp, -1, sizeof dp);
    dp[0][r] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (R << 1); ++j) if (dp[i][j] != -1) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j >= c[i + 1].first && j + c[i + 1].second >= 0 && j + c[i + 1].second < (R << 1) )
                dp[i + 1][j + c[i + 1].second ] = max(dp[i + 1][j + c[i + 1].second ], dp[i][j] + 1);
        }
    }

    int ans = -1;
    for (int i = 0; i < (R << 1); ++i) ans = max(ans, dp[n][i]);

    cout << ans;

    return 0;
}