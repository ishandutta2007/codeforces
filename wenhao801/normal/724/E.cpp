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

const int MAXN = 10010;

int n, c;
int p[MAXN], s[MAXN];
int dp[2][MAXN] = {};

signed main () {
    n = read(), c = read();
    int i, j;
    for (i = 1; i <= n; i++) p[i] = read();
    for (i = 1; i <= n; i++) s[i] = read();
    for (i = 1; i <= n; i++) for (j = 0; j <= i; j++) {
        int t = i & 1, tt = t ^ 1;
        dp[t][j] = 2345678987654372634ll;
        if (j) dp[t][j] = min(dp[t][j], dp[tt][j - 1] + s[i]);
        if (j != i) dp[t][j] = min(dp[t][j], dp[tt][j] + p[i] + j * c);
    }
    for (i = 0, j = 456789098765456789ll; i <= n; i++) j = min(j, dp[n & 1][i]);
    printf("%lld\n", j);
    return 0;
}