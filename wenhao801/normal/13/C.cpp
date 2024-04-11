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

int n;
int a[5050] = {};
int b[5050] = {};

int dp[5050] = {};

signed main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = b[i] = read();
    sort(b + 1, b + n + 1); dp[0] = 123456789987654ll;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) 
            dp[j] = min(dp[j - 1], dp[j] + abs(a[i] - b[j]));
    }
    printf("%lld\n", dp[n]);
    return 0;
}