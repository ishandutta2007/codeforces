#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> a(n), sum(n + 1);
        for(int i = 0; i < n; ++i) cin >> a[i];
        reverse(a.begin(), a.end());
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
        vector<ll> dp(n + 1, -1e18);
        for(int i = 1; i <= n; ++i) dp[i] = max(dp[i - 1], a[i - 1]);
        for(int k = 2; k <= n; ++k) {
            vector<ll> ndp(n + 1, -1e18);
            ll mx = -1e18;
            for(int i = k; i <= n; ++i) {
                ndp[i] = ndp[i - 1];
                if(i - k >= 0) mx = max(mx, dp[i - k]);
                if(sum[i] - sum[i - k] < mx) {
                    ndp[i] = max(ndp[i], sum[i] - sum[i - k]);
                }
            }
            dp = ndp;
            if(ndp.back() == -1e18) {
                cout << k - 1 << '\n';
                break;
            }
        }
    }
}