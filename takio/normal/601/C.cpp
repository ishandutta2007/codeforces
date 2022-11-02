#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 1000010;

long double dp[2][N], sum[N];
int a[1100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, all = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all += a[i];
    }
    int now = 0;
    dp[now][0] = m - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * m; j++) sum[j] = (j - 1 < 0 ? 0 : sum[j - 1]) + dp[now][j];
        memset (dp[now ^ 1], 0, sizeof dp[now ^ 1]);
        for (int j = i; j <= n * m; j++) {
            dp[now ^ 1][j] = sum[j - 1] - (j - m - 1 < 0 ? 0 : sum[j - m - 1]) - (j - a[i] < 0 ? 0 : dp[now][j - a[i]]);
//            cout << j << ' ' << sum[j - 1] << endl;
            dp[now ^ 1][j] /= m - 1;
        }
        now ^= 1;
    }
    long double res = 0;
//    for (int i = 1; i <= n * m; i++) cout << i << ' ' << dp[now][i] << endl;
    for (int i = n; i < all; i++) res += dp[now][i];
    printf ("%.12f\n", (double)res + 1);
}