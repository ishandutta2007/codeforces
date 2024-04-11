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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 1; i < n; ++i) a[i] -= a[0]; a[0] = 0;
        int m = n / 2, mx = *max_element(a.begin(), a.end());
        int ans = 0, ok = 0;
        for(int i = 0; i <= m; ++i) {
            vector<set<int>> dp(m + 1);
            dp[1].insert(0);
            for(int j = i + 1; j < n; ++j) {
                for(int k = m - 1; k >= 1; --k) {
                    for(int p : dp[k]) {
                        dp[k + 1].insert(gcd(p, a[j] - a[i]));
                    }
                }
            }
            for(int j : dp[m]) {
                if(j == 0) {
                    ok = 1;
                    break;
                }
                ans = max(ans, j);
            }
        }
        if(ok) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}