#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int a[300300], b[300300];
int dp[300300];
int dp2[300300];

signed main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        for (i = 1; i <= n; i++) dp[i] = dp2[i] = 0;
        for (i = 1; i <= n; i++) a[i] = read(), b[i] = read();
        dp[1] = a[1];
        for (i = 2; i <= n; i++) dp[i] = dp[i - 1] + max(0ll, a[i] - b[i - 1]);
        dp2[n] = 0;
        for (i = n - 1; i >= 1; i--) dp2[i] = max(0ll, a[i + 1] - b[i]) + dp2[i + 1];
        int ans = dp[n];
        for (i = 2; i <= n; i++) {
            int tmp = a[i] + dp2[i] + dp[i - 1];
            tmp -= min(b[n], a[1]);
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}