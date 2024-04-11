#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define LL long long
using namespace std;

int a[5010];
LL sum[5010], dp[5010][5010];

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int INF = -1;
    for (int i = 1; i <= k; i++) dp[0][i] = -1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j != 0 && i >= m && dp[i - m][j - 1] != INF){
                dp[i][j] = max (dp[i][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);
            }
        }
    }
    cout << dp[n][k];
}