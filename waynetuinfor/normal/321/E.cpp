#include <bits/stdc++.h>
#define getchar gtx
// This is fucking fast
using namespace std;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 4000 + 10, maxk = 800 + 10;
const long long inf = 1e18 + 1;
long long s[maxn][maxn], dp[maxn][maxn], f[maxn][maxn];

long long get(int l, int r) {
    return s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1];
}

void go(int k, int l, int r, int fl, int fr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    f[k][m] = -1;
    for (int i = fl; i <= min(fr, m - 1); ++i) {
        long long t = dp[k - 1][i] + get(i + 1, m) / 2;
        if (t < dp[k][m]) {
            dp[k][m] = t;
            f[k][m] = i;
        }
    }
    go(k, l, m - 1, fl, f[k][m]); go(k, m + 1, r, f[k][m], fr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; rit(n, k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a; rit(a);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a;
        }
    }
    for (int i = 0; i < maxk; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) go(i, 1, n, 0, n - 1);
    printf("%I64d\n", dp[k][n]);
    return 0;
}