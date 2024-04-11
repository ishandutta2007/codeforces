#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        int ok = 0;
        {
            int j = 0, okk = 1;
            for(int i = 0; i < t.size(); ++i) {
                while(j < s.size() && s[j] != t[i]) ++j;
                if(j == s.size()) {
                    okk = 0;
                    break;
                }
                ++j;
            }
            if(okk) ok = 1;
        }
        for(int i = 1; i < t.size(); ++i) {
            // [0,i) [i,t.size())
            vector<vector<int>> dp(s.size() + 1, vector<int>(i + 1, -1));
            dp[0][0] = i;
            for(int j = 1; j <= s.size(); ++j) {
                for(int k = 0; k <= i; ++k) {
                    dp[j][k] = dp[j-1][k];
                    if(dp[j-1][k] != -1 && dp[j-1][k] < t.size() && s[j-1] == t[dp[j-1][k]]) {
                        dp[j][k] = dp[j-1][k] + 1;
                    }
                    if(k - 1 >= 0 && s[j-1] == t[k-1]) {
                        dp[j][k] = max(dp[j][k], dp[j-1][k-1]);
                    }
                    if(k == i && dp[j][k] == t.size()) {
                        ok = 1;
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}