#include <bits/stdc++.h>
using namespace std;

long long dp[51][2501];

int main() {
    int n;
    long long mod; cin >> n >> mod;
    /*
     * dp[i][j] is number of permutations of i elements with j inversions
     */
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= 50 * (50 - 1) / 2; j++) {
            if(j == 0) dp[i][j] = 1LL;
            else if(i == 0) {
                dp[i][j] = 0LL;
            }
            else {
                for(int put = i - 1; put >= 0; put--)
                    if(put <= j)
                        dp[i][j] += dp[i - 1][j - put], dp[i][j] %= mod;
                dp[i][j] %= mod;
            }
        }
    }
    long long ans = 0LL;
    for(int same = 0; same < n; same++) {
        long long num = 1LL;
        for(int j = 0; j < same; j++)
            num *= (n - j), num %= mod;
        long long tmp = 0LL;
        int left = n - same;
        for(int d = 1; d < left; d++) {
            int mult = (left - d);
            long long sum = 0LL;
            long long add = 0LL;
            for(int j = d; j <= 50 * (50 - 1) / 2; j++) {
                add += dp[left - 1][j] * 1LL * sum;
                add %= mod;
                sum += dp[left - 1][j - d], sum %= mod;
            }
            add *= mult;
            add %= mod;
            tmp += add;
            tmp %= mod;
        }
        tmp *= num;
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    if(ans < 0) ans += mod;
    cout << ans;
}