#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 30;

ll dp[MN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(dp, 0);
        string s; cin >> s;
        s.push_back('0'); s.push_back('0');
        reverse(s.begin(), s.end());
        s.push_back('0'); s.push_back('0');
        dp[0][0] = dp[1][0] = 1;
        for (char &c : s) c -= '0';
        for (int i = 2; i < s.size(); ++i){
            for (int a = 0; a <= 9; ++a){
                for (int b = 0; b <= 9; ++b){
                    int rem = (a + b) % 10;
                    int carry = (a + b) / 10;
                    if (rem == s[i]) dp[i][carry] += dp[i - 2][0];
                    rem = (a + b + 1) % 10;
                    carry = (a + b + 1) / 10;
                    if (rem == s[i]) dp[i][carry] += dp[i - 2][1];
                }
            }
        }
        int n = s.size() - 1;
        cout << dp[n][0] * dp[n - 1][0] - 2 << '\n';
    }
}