#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
long long tpow[500005];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t; cin >> t;
    long long MOD = 998244353;
    tpow[0] = 1LL;
    for (int i = 1; i <= 500000; i++) {
        tpow[i] = tpow[i - 1] * 2 % MOD;
    }
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int numOne = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                ++numOne;
            }
        }
        tpow[0] = 1LL;
        vector<long long> dp(n + 1);
        vector<long long> f(n + 1);
        vector<long long> dpb(n + 1);
        vector<int> g(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == 0) {
                dp[i] = 1 + f[0];
            } else {
                dp[i] = f[a[i - 1]] + f[a[i - 1] - 1];
            }
            dp[i] %= MOD;
            f[a[i - 1]] += dp[i];
            f[a[i - 1]] %= MOD;
        }
        for (int i = n; i >= 1; i--) {
            dpb[i] = 1LL;
            if (a[i - 1] - 2 >= 0) {
                dpb[i] = tpow[g[a[i - 1]] + g[a[i - 1] - 2]];
            } else {
                dpb[i] = tpow[g[a[i - 1]]];
            }
            dpb[i] %= MOD;
            ++g[a[i - 1]];
        }
        vector<long long> freq(n + 1);
        long long ans = tpow[numOne] - 1;
        //0001111...iiii...(i+2) (alternate between (i+2) and (i)))
        for (int i = n; i >= 1; i--) {
            if (a[i - 1] <= n - 2) {
                ans += dp[i] * 1LL * (freq[a[i - 1] + 2] + 1);
            } else {
                ans += dp[i];
            }
            ans %= MOD;
            freq[a[i - 1]] += dpb[i];
            freq[a[i - 1]] %= MOD;
        }
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}