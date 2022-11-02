#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
#define pii pair <int, int>
using namespace std ;

const int N = 2222, mod = 1e9 + 7;

int n;
int a[N];
LL c[N][N], dp[N][N], sum[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            (c[i][j] = c[i - 1][j] + c[i - 1][j - 1]) %= mod;
        }
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        scanf ("%d", &a[i]);
    }
    dp[k + 1][1] = 1;
    for (int i = k; i >= 1; i--) {
        sum[N - 1] = 0;
        for (int j = N - 2; j >= 0; j--) (sum[j] = sum[j + 1] + dp[i + 1][j]) %= mod;
//        for (int j = 0; j < 10; j++) cout << dp[i][j] << ' '; cout << endl;
        for (int j = a[i]; j < N; j++) {
//            if (i == k && j == a[i]) cout << j << ' ' << c[j][a[i] - 1] << ' ' << sum[j - a[i]] << endl;
            dp[i][j] = c[j - 1][a[i] - 1] * sum[j - a[i] + 1] % mod;
//            if (dp[i][j]) cout << i << ' ' << j <<  ' ' << c[j - 1][a[i] - 1] << ' ' << sum[j - a[i] + 1] << endl;
        }
//        for (int j = 0; j < 10; j++) cout << dp[i][j] << ' '; cout << endl;
    }
    LL res = 0;
    for (int i = 0; i < N; i++) res += dp[1][i];
    res %= mod;
    cout << res << endl;
}