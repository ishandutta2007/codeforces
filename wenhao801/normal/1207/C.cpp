#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

#define int long long

using namespace std;

const int inf = LLONG_MAX;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

char s[200200] = {};
int t[200200] = {};
int n, a, b;
int dp[5][5] = {};

signed main () {
    int T = read();
    while (T--) {
        n = read(), a = read(), b = read();
        scanf("%s", s);
        memset(dp, 0, sizeof(dp));
        dp[0][1] = b, dp[0][2] = inf;
        int i, j;
        for (i = 1; i < n; i++) t[i] = (s[i - 1] - '0') | (s[i] - '0');
        t[0] = t[n] = 0;
        int now = 0;
        for (i = 1; i <= n; i++) {
            now ^= 1;
            dp[now][1] = dp[now][2] = inf;
            if (dp[now ^ 1][1] != inf) {
                dp[now][2] = min(dp[now][2], dp[now ^ 1][1] + 2 * a + 2 * b);
                if (t[i] == 1) dp[now][1] = inf;
                else dp[now][1] = min(dp[now][1], dp[now ^ 1][1] + a + b);
            }
            if (dp[now ^ 1][2] != inf) {
                dp[now][2] = min(dp[now][2], dp[now ^ 1][2] + a + 2 * b);
                if (t[i] == 1) dp[now][1] = inf;
                else dp[now][1] = min(dp[now][1], dp[now ^ 1][2] + 2 * a + b);
            }
            //cout << dp[now][1] << ' ' << dp[now][2] << endl;
        }
        printf("%lld\n", dp[now][1]);
    }
    return 0;
}