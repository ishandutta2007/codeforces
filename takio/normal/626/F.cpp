#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 520, mod = 1e9 + 7;
int c[N];
int dp[2][110][1010];

inline void add (int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, K, a;
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        c[a]++;
    }
    int now = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        memset (dp[now ^ 1], 0, sizeof dp[now ^ 1]);
        for (int j = 0; j * 2 <= n; j++) {
            for (int k = 0; j + k <= K; k++) if (dp[now][j][k]) {
                add (dp[now ^ 1][j][k + j], dp[now][j][k]);
            }
        }
        now ^= 1;
        for (int l = 1; l <= c[i]; l++) {
            memset (dp[now ^ 1], 0, sizeof dp[now ^ 1]);
            for (int j = 0; j * 2 <= n; j++) {
                for (int k = 0; k <= K; k++) if (dp[now][j][k]) {
                    add (dp[now ^ 1][j + 1][k], dp[now][j][k]);
                    add (dp[now ^ 1][j][k], 1LL * dp[now][j][k] * (j + 1) % mod);
                    if (j) add (dp[now ^ 1][j - 1][k], 1LL * dp[now][j][k] * j % mod);
                }
            }
            now ^= 1;
        }
    }
    int res = 0;
    for (int i = 0; i <= K; i++) add (res, dp[now][0][i]);
    cout << res << endl;
}