#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll dp[1005][1005][2][2][2];
int main() {
    string s, t;
    cin >> s >> t;
    for(int i = 0; i <= s.size(); ++i) {
        for(int j = 0; j <= t.size(); ++j) {
            if(i) dp[i][j][1][0][0] = 1;
            if(j) dp[i][j][0][1][1] = 1;
        }
    }
    for(int i = 0; i <= s.size(); ++i) {
        for(int j = 0; j <= t.size(); ++j) {
            for(int f1 = 0; f1 < 2; ++f1) {
                for(int f2 = 0; f2 < 2; ++f2) {
                    for(int k = 0; k < 2; ++k) {
                        char c = -1;
                        if(i && k == 0) c = s[i-1];
                        if(j && k == 1) c = t[j-1];
                        if(i < s.size() && s[i] != c) {
                            dp[i+1][j][1][f2][0] = (dp[i+1][j][1][f2][0] + dp[i][j][f1][f2][k]) % mod;
                        }
                        if(j < t.size() && t[j] != c) {
                            dp[i][j+1][f1][1][1] = (dp[i][j+1][f1][1][1] + dp[i][j][f1][f2][k]) % mod;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= s.size(); ++i) {
        for(int j = 1; j <= t.size(); ++j) {
            ans += dp[i][j][1][1][0] + dp[i][j][1][1][1];
        }
    }
    cout << ans % mod << endl;
}