#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int dp[100010][3], a[100010];

int main () {
    int n, res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &a[i]);
    }
    if (n == 1){cout << 1; return 0;}
    dp[1][1] = dp[1][0] = 1;
    if (a[2] > a[1]) dp[2][1] = 2, dp[2][0] = 2;
    else dp[2][1] = 1, dp[2][0] = 2;
    res = max (res, dp[2][0]);
    res = max (res, dp[2][1]);
//    a[n + 1] = 1e9 + 1;
//    a[n + 2] = 1e9 + 2;
    for (int i = 3; i <= n; i++)
    {
        if (a[i] > a[i - 1])
            dp[i][1] = dp[i - 1][1] + 1,
            dp[i][0] = dp[i - 1][0] + 1;
        else
            dp[i][1] = 1,
            dp[i][0] = 2,
            res = max (res, dp[i - 1][1] + 1);

        if (a[i] > a[i - 2] + 1)
            dp[i][0] = max (dp[i][0], dp[i - 2][1] + 2);
        else
            dp[i][0] = max (dp[i][0], 2);
//        dp[i][0] = max (dp[i][0], dp[i - 1][1] + 1);
//        cout << dp[i][0] << ' ' << dp[i][1] << endl;
        res = max (res, dp[i][0]);
        res = max (res, dp[i][1]);
    }
    res = max (res, dp[n - 1][1] + 1);
    cout << res;
}