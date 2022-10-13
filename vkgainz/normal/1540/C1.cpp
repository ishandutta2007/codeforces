#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> c(n), b(n - 1);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int q; cin >> q;
    int Q; cin >> Q;

    vector<int> need_sum(n);
    need_sum[0] = Q;
    int sum = 0;
    for(int i = 1; i < n; i++) {
        sum += b[i - 1];
        need_sum[i] = need_sum[i - 1] + Q + sum;
    }
    for(int i = 0; i < n; i++) need_sum[i] = max(need_sum[i], 0);

    vector<vector<long long>> dp(n + 1, vector<long long>(10001));
    dp[0][0] = 1LL;
    long long MOD = 1e9 + 7;
    long long ans = 0LL;
    for(int i = 1; i <= n; i++) {
        for(int make = need_sum[i - 1]; make <= 10000; make++) {
            for(int take = 0; take <= min(make, c[i - 1]); take++) {
                dp[i][make] += dp[i - 1][make - take];
                dp[i][make] %= MOD;
            }
            if(i == n)
                ans += dp[i][make], ans %= MOD;
        }
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}