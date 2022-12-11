#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7;
int dp[N][2][2];
int val[N];

int calc(int n, int d1, int d2) {
    dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = N * 3;
    dp[2][d1][d2] = 0;
    if (d1 != val[1]) dp[2][d1][d2]++;
    if (d2 != val[2]) dp[2][d1][d2]++;
    for (int i = 3; i <= n; i++) {
        for (int lst = 0; lst <= 1; lst++) {
            int cur = 0;
            if (lst != val[i]) cur++;
            if (lst == 0) {
                dp[i][0][lst] = cur + dp[i - 1][1][0];
                dp[i][1][lst] = cur + min(dp[i - 1][1][1], dp[i - 1][0][1]);
                //dp[i][ = cur + min(dp[i - 1][0][1], min(dp[i - 1][1][0], dp[i - 1][1][1]));
            } else {
                dp[i][1][lst] = cur + dp[i - 1][0][1]; 
                dp[i][0][lst] = cur + min(dp[i - 1][1][0], dp[i - 1][0][0]);
            }
            //dp[i][lst] = cur + min()
        }
    }
    int res;
    if (d1 == 0 && d2 == 0) {
        res = min(dp[n][0][1], dp[n][1][1]);
    }
    if (d1 == 0 && d2 == 1) {
        res = min(dp[n][1][1], min(dp[n][0][1], dp[n][1][0]));
    }
    if (d1 == 1 && d2 == 0) {
        res = min(dp[n][0][0], min(dp[n][0][1], dp[n][1][0]));
    }
    if (d1 == 1 && d2 == 1) {
        res = min(dp[n][0][0], dp[n][1][0]);
    }
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < (int) s.length(); i++) {
            if (s[i] == 'L') val[i + 1] = 0;
            else val[i + 1] = 1;
        }
        int res = (calc(n, 0, 0));
        res = min(res, calc(n, 0, 1));
        res = min(res, calc(n, 1, 0));
        res = min(res, calc(n, 1, 1));
        cout << res << "\n";
    }
    return 0;
}