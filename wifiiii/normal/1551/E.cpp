#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i]; --a[i];
            a[i] = i - a[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1));
        int ans = 1e9;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(i) {
                    if(a[i] == j) dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]);
                } else {
                    if(a[i] == j) dp[i][j]++;
                }
                if(dp[i][j] >= k) ans = min(ans, j);
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}