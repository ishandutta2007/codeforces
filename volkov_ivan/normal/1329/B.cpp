#include <bits/stdc++.h>
#define int long long

using namespace std;

const int K = 31;
//int dp[K];

void solve() {
    int m, d;
    cin >> d >> m;
    //memset(dp, 0, sizeof(dp));
    int summ = 1;
    for (int i = 0; i < K; i++) {
        int start = (1 << i);
        if (start > d) break;
        int cnt = start;
        cnt = min(cnt, d - start + 1);
        int cur = (cnt * summ) % m;
        summ = (summ + cur) % m;
    }
    summ = (summ - 1 + m) % m;
    cout << summ << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}