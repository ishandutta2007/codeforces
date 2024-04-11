#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 10100;
LL dp[2][N];
int a[N], b[N];
inline void add (LL &a, LL b) {
    a = min (a, b);
}

int main ()
{
//    freopen ("in", "r", stdin);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf ("%d", &b[i]);
    memset (dp, 0x3f, sizeof dp);
    int now = 0;
    LL INF = dp[0][0];
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        memset (dp[now ^ 1], 0x3f, sizeof dp[now ^ 1]);
        for (int j = 0; j <= i; j++) if (dp[now][j] != INF) {
//            cout << i << ' ' << j << ' ' << dp[now][j] << endl;
            add (dp[now ^ 1][j], dp[now][j] + 1LL * j * c + a[i + 1]);
//            add (dp[now ^ 1][j], dp[now][j] + b[i + 1] + a[i + 1]);
            add (dp[now ^ 1][j + 1], dp[now][j] + b[i + 1]);
//            add (dp[now ^ 1][j + 1], dp[now][j] + b[i + 1]);
        }
        now ^= 1;
    }
    LL res = 1LL << 62;
    for (int i = 0; i <= n; i++) {
        add (res, dp[now][i]);
    }
    cout << res << endl;
    return 0;
}