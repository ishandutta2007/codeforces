#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 2010;

double dp[N][N];

int main () {
    double p;
    int n, t;
    cin >> n >> p >> t;
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j] += dp[i][j] * (1 - p);
            dp[i + 1][j + 1] += dp[i][j] * p;
        }
        dp[i + 1][n] += dp[i][n];
    }
    double res = 0;
    for (int i = 1; i <= n; i++) res += dp[t][i] * i;
    printf ("%.10f", res);
}