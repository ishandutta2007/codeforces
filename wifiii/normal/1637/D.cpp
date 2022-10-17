#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        ll ans = 0; int s = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], ans += 1ll * a[i] * a[i] * (n - 2), s += a[i];
        for(int i = 0; i < n; ++i) cin >> b[i], ans += 1ll * b[i] * b[i] * (n - 2), s += b[i];
        vector<int> dp(n * 100 + 1);
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            vector<int> ndp(n * 100 + 1);
            for(int j = 0; j <= i * 100; ++j) {
                if(dp[j]) ndp[j + a[i]] = ndp[j + b[i]] = 1;
            }
            dp = ndp;
        }
        ll mn = 1e18;
        for(int i = 0; i <= n * 100; ++i) {
            if(dp[i]) {
                mn = min(mn, 1ll * i * i + 1ll * (s - i) * (s - i));
            }
        }
        ans += mn;
        cout << ans << '\n';
    }
}