#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> x(n), y(n), s(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    
    vector<long long> dp(n);
    vector<long long> val(n); //transition sim to dp
    dp[0] = x[0] + x[0] - y[0];
    if(s[0]) val[0] = dp[0];
    else val[0] = x[0];

    for(int i = 1; i < n; i++) {
        if(y[i] > x[i - 1]) {
            dp[i] = dp[i - 1] + x[i] - x[i - 1] + x[i] - y[i];
            if(s[i]) {
                val[i] = val[i - 1] + x[i] - x[i - 1] + x[i] - y[i];
            }
            else {
                val[i] = val[i - 1] + x[i] - x[i - 1];
            }
        }
        else {
            int lo = 0, hi = i - 1;
            for(int j = 0; j < 20; j++) {
                int mid = (lo + hi) / 2;
                if(x[mid] > y[i])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            dp[i] = dp[i - 1] + 2 * (x[i] - x[i - 1]);
            if(lo == 0) {
                dp[i] += dp[i - 1] - y[i];
            }
            else {
                dp[i] += dp[i - 1] - (y[i] - x[lo - 1]) - dp[lo - 1];
            }
            if(s[i]) {
                val[i] = val[i - 1] + 2 * (x[i] - x[i - 1]);
                if(lo == 0) {
                    val[i] += dp[i - 1] - y[i];
                }
                else {
                    val[i] += dp[i - 1] - (y[i] - x[lo - 1]) - dp[lo - 1];
                }
            }
            else {
                val[i] = val[i - 1] + x[i] - x[i - 1];
            }
            dp[i] %= MOD, val[i] %= MOD;
        }
    }
    long long ans = val[n - 1] + 1;
    ans %= MOD;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}