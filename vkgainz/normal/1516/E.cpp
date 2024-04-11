#include <bits/stdc++.h>
using namespace std;

long long get_inv(long long b, long long p, long long MOD) { if(p == 0) return 1LL;
    long long x = get_inv(b, p / 2, MOD);
    x = x * x % MOD;
    if(p % 2) x = x * b % MOD;
    return x;
}

vector<long long> inv(401);
long long MOD = 1e9 + 7;

long long choose(int n, int k) {
    if(k > n) return 0LL;

    long long ans = 1LL;
    for(int i = n; i >= n - k + 1; i--) {
        ans *= i, ans %= MOD;
    }
    for(int i = 1; i <= k; i++) {
        ans *= inv[i], ans %= MOD;
    }
    return ans;
}


long long ch[401][401];
int main() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= 400; i++)
        inv[i] = get_inv(i, MOD - 2, MOD);

    vector<vector<long long>> dp(2 * k + 1, vector<long long>(k + 1));
    fill(dp[0].begin(), dp[0].end(), 1);
    for(int i = 1; i <= 2 * k; i++) {
        for(int j = 0; j <= k; j++) {
            if(j == 0) dp[i][j] = 1LL;
            else {
                dp[i][j] = dp[i - 1][j] + (i - 1) * 1LL * dp[i - 1][j - 1] % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    ch[0][0] = 1LL;
    for(int i = 1; i <= 400; i++)
        ch[i][0] = 1LL;
    for(int i = 1; i <= 400; i++)
        for(int j = 1; j <= 400; j++)
            ch[i][j] = (ch[i - 1][j] + ch[i - 1][j - 1]) % MOD;
    vector<long long> ans(k + 1);
    for(int i = 0; i <= k; i++) {
        for(int sz = 0; sz <= 2 * i; sz++) {
            long long mult = choose(n, sz);
            for(int off = 0; off <= sz; off++) {
               long long x = ch[sz][off];
               if(off % 2 == 0) ans[i] += mult * 1LL * x % MOD * 1LL * dp[sz - off][i] % MOD;
               else ans[i] -= mult * 1LL * x % MOD * 1LL * dp[sz - off][i] % MOD;
               ans[i] %= MOD;
            }
        }
    }
    for(int i = 1; i <= k; i++) {
        ans[i] -= ans[i - 1];
        ans[i] %= MOD;
        if(ans[i] < 0) ans[i] += MOD;
        cout << ans[i] << " ";
    }
    cout << "\n";
}