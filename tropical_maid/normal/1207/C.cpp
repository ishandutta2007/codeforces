#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/22, 23:48:30
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const llong inf = 1e18;
int n, a, b;
char S[200002];

llong solve() {
    cin >> n >> a >> b >> S;
    llong dp[2] = { b, inf }, tp[2];
    for (int i = 1; i <= n; ++i) {
        if (S[i - 1] == '1' || S[i] == '1') {
            tp[0] = inf;
            tp[1] = min(dp[0] + a, dp[1]);
        }
        else {
            tp[0] = min(dp[0], dp[1] + a);
            tp[1] = min(dp[0] + a, dp[1]);
        }
        dp[0] = tp[0] + b;
        dp[1] = tp[1] + b + b;
    }
    return dp[0] + (llong)a * n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}