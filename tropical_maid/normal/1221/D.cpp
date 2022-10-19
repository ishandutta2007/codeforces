#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/19, 23:50:51
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const llong inf = 1e18;
int n;
int A[300001];
int B[300001];
llong solve() {
    cin >> n >> A[1] >> B[1];
    llong dp[3] = {}, tp[3] = {};
    for (int i = 0; i < 3; ++i) {
        dp[i] = (llong)B[1] * i;
        tp[i] = inf;
    }
    for (int i = 2; i <= n; ++i) {
        cin >> A[i] >> B[i];
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (A[i - 1] + j == A[i] + k) continue;
                tp[k] = min(tp[k], dp[j] + (llong)B[i] * k);
            }
        }
        for (int j = 0; j < 3; ++j) {
            dp[j] = tp[j];
            tp[j] = inf;
        }
    }
    llong ret = inf;
    for (int i = 0; i < 3; ++i) ret = min(ret, dp[i]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}