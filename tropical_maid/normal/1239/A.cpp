#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/10/20, 18:05:25
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int mod = 1e9 + 7;
int dp[100002][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0][0] = 0;
    dp[0][1] = 2;
    for (int i = 1; i <= 100001; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = dp[i - 1][0];
    }
    int ans = (dp[n + 1][0] + dp[m + 1][0]) % mod;
    ans = (ans + mod - 2) % mod;
    printf("%d\n", ans);
    return 0;
}