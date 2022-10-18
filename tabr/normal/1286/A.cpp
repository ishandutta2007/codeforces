#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    int odd = (n + 1) / 2, even = n / 2;
    rep(i, 0, n) {
        cin >> p[i];
        if (p[i] % 2 == 1) {
            odd--;
            p[i] = 1;
        } else if (p[i]) {
            even--;
            p[i] = 2;
        }
    }
    int cnt = odd + even;
    int dp[n + 1][2][odd + 1][even + 1];
    memset(dp, 0x7f, sizeof(dp));

    if (p[0] == 1) {
        dp[1][1][odd][even] = 0;
    } else if (p[0] == 2) {
        dp[1][2][odd][even] = 0;
    } else {
        dp[1][1][odd - 1][even] = 0;
        dp[1][2][odd][even - 1] = 0;
        cnt--;
    }
    // cout << min(dp[n][1][0][0], dp[n][2][0][0]) << endl;

    rep(i, 1, n) {
        if (p[i] == 1) {
            rep(j, 0, min(cnt, odd) + 1) dp[i + 1][1][j][cnt - j] =
                min(dp[i][1][j][cnt - j], dp[i][2][j][cnt - j] + 1);
        } else if (p[i] == 2) {
            rep(j, 0, min(cnt, even) + 1) dp[i + 1][2][cnt - j][j] =
                min(dp[i][2][cnt - j][j], dp[i][1][cnt - j][j] + 1);
        } else {
            rep(j, 1, min(cnt, odd) + 1) dp[i + 1][1][j - 1][cnt - j] =
                min(dp[i][1][j][cnt - j], dp[i][2][j][cnt - j] + 1);
            rep(j, 1, min(cnt, even) + 1) dp[i + 1][2][cnt - j][j - 1] =
                min(dp[i][2][cnt - j][j], dp[i][1][cnt - j][j] + 1);
            cnt--;
        }
    }
    cout << min(dp[n][1][0][0], dp[n][2][0][0]) << endl;
    return 0;
}