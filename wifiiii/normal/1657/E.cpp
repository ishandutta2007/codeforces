#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll fpow(ll n, ll k) {
    ll ret = 1;
    while(k) {
        if(k & 1) ret = ret * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ret;
}
ll solve(int n, int k) {
    vector<ll> dp(n);
    dp[0] = 1;
    vector<vector<ll>> pw(k + 1, vector<ll>(n * n + 1));
    vector<ll> f(n + 1), rf(n + 1);
    f[0] = 1; for(int i = 1; i <= n; ++i) f[i] = f[i - 1] * i % mod;
    rf[n] = fpow(f[n], mod - 2); for(int i = n - 1; i >= 0; --i) rf[i] = rf[i + 1] * (i + 1) % mod;
    for(int i = 1; i <= k; ++i) {
        pw[i][0] = 1;
        for(int j = 1; j <= n * n; ++j) {
            pw[i][j] = pw[i][j - 1] * i % mod;
        }
    }
    for(int i = 1; i <= k; ++i) {
        vector<ll> ndp(n);
        for(int j = 0; j <= n - 1; ++j) {
            if(dp[j] == 0) continue;
            for(int c = 0; c + j <= n - 1; ++c) {
                ndp[c + j] += dp[j] * pw[k + 1 - i][c * j + c * (c - 1) / 2] % mod * rf[c] % mod;
                if(ndp[c + j] >= mod) ndp[c + j] %= mod;
            }
        }
        dp = ndp;
    }
    return dp[n - 1] * f[n - 1] % mod;
} 
int main() {
    // freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
}