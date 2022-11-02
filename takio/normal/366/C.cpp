#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
#define ULL unsigned long long
using namespace std;

const int N = 210, M = 150010;
int dp[N][M * 2], a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] *= k;
    }
    memset (dp, -1, sizeof dp);
    dp[0][M] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M * 2; j++) if (dp[i][j] != -1) {
            dp[i + 1][j] = max (dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + a[i + 1] - b[i + 1]] = max (dp[i + 1][j + a[i + 1] - b[i + 1]], dp[i][j] + a[i + 1]);
        }
    }
    int res = dp[n][M];
    if (res == 0) res = -1;
    cout << res << endl;
}