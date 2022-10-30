#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;

LL dp[1100][110], p[1100][15], f[1100];

int main () {
    LL n, m, mod;
    cin >> n >> m >> mod;
    if (mod == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (LL j = 1; j <= 9; j++) {
        p[1][j] = j % mod;
//        cout << j << ' ' << p[1][j] << endl;
    }
    for (LL i = 2; i <= n; i++) {
        for (LL j = 1; j <= 9; j++) {
            p[i][j] = p[i - 1][j] * 10 % m;
//            cout << i << ' ' << j << ' ' << p[i][j] << endl;
        }
    }
    f[0] = 1; f[1] = 9;
    for (LL i = 2; i <= n; i++) {
        f[i] = f[i - 1] * 10 % mod;
    }
    for (LL i = 1; i <= 9; i++) (dp[1][i % m] += 1) %= mod;
    LL res = 0;
    for (LL i = 1; i < n; i++) {
        for (LL j = 1; j <= 9; j++) (dp[i + 1][p[i + 1][j] % m] += 1) %= mod;
        for (LL j = 1; j < m; j++) if (dp[i][j]) {
            for (LL k = 0; k <= 9; k++) {
                (dp[i + 1][(j + p[i + 1][k]) % m] += dp[i][j]) %= mod;
//                if ((j + p[i + 1][k]) % m == 0 && k) (res += dp[i][j] * f[n - i - 1]) %= mod;
            }
        }
    }
//    for (LL i = 1; i <= n; i++) {
//        for (LL j = 0; j < m; j++) {
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//        }
//    }
    for (LL i = 1; i <= n; i++) {
//        cout << "dp" << i << ' ' << dp[i][0] << endl;
        (res += dp[i][0] * f[n - i]) %= mod;
    }
    cout << res << endl;
}