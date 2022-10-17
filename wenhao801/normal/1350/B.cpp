#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int dp[MAXN], a[MAXN];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) dp[i] = 0;
        for (i = 1; i <= n; i++) {
            dp[i] = max(dp[i], 1);
            for (j = i + i; j <= n; j += i) if (a[i] < a[j]) dp[j] = max(dp[j], dp[i] + 1);
        }
        int ans= 0;
        for (i = 1; i <= n; i++) ans = max(ans, dp[i]); cout << ans << endl;
    }
    return 0;
}