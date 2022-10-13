#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--) {
        string s, t; cin >> s >> t;
        int n = (int) s.length(), m = (int) t.length();
        vector<vector<bool>> dp(s.length() + 5, vector<bool>(t.length() + 5));
        for(int i = 0; i < n; i++) {
            dp[i][m] = true;
            dp[i][m - 1] = (s[i] == t[m - 1]);
            for(int j = m - 2; j >= 0; j--) {
                if(s[i] == t[j] && i > 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j + 1];
            }
        }
        bool ans = false;
        for(int pivot = 0; pivot < n; pivot++) {
            ans = ans || dp[pivot][0];
            for(int r = 0; r <= n - pivot - 1; r++) {
                if(s[pivot + r] != t[r]) break;
                //[pivot + r + 1...m - 1]
                if(pivot + r - 1 > 0)
                    ans = ans || dp[pivot + r - 1][r + 1];
            }
        }
        if(ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}