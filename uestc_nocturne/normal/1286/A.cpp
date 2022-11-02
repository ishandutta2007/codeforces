/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 110;
const int oo = 1000000000;
int dp[V][V][V][2];
int n, a[V], vis[V];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int odd = (n + 1) / 2;
        int even = n / 2;
        for (int i = 0; i < n; ++i)
            if (a[i] != 0) {
                if (a[i] % 2 == 1) --odd;
                else --even;
            }
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= odd; j++)
                for (int k = 0; k <= even; ++k)
                    dp[i][j][k][0] = dp[i][j][k][1] = oo;
        dp[0][0][0][0] = dp[0][0][0][1] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= odd; ++j) {
                for (int k = 0; k <= even; ++k) {
                    for (int last = 0; last < 2; ++last) {
                        if (a[i] == 0) {
                            if (j != odd) {
                                dp[i + 1][j + 1][k][1] = min(dp[i + 1][j + 1][k][1], dp[i][j][k][last] + ((last + 1) % 2));
                            }
                            if (k != even) {
                                dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][last] + ((last + 0) % 2));
                            }
                        } else {
                            dp[i + 1][j][k][a[i] % 2] = min(dp[i + 1][j][k][a[i] % 2], dp[i][j][k][last] + ((last + a[i]) % 2));
                        }
                    }
                }
            }
        }
        printf("%d\n", min(dp[n][odd][even][0], dp[n][odd][even][1]));
    }
    return 0;
}

/*
5
0 5 0 2 3
7
1 0 0 5 0 0 2

*/