#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3007, M = 998244353;
int dp[N][N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--) {
        for (int beg = 0; beg <= n; beg++) {
            if (beg == 0 && i >= m) {
                dp[i][beg] = (dp[i][beg] + 1) % M;
            }
            if ((beg < m && s[i - 1] == t[beg]) || beg >= m) {
                dp[i - 1][beg + 1] = (dp[i - 1][beg + 1] + dp[i][beg]) % M;
            }
            if ((i - 1 + beg >= m) || ((i - 1 + beg < m) && s[i - 1] == t[i - 1 + beg])) {
                dp[i - 1][beg] = (dp[i - 1][beg] + dp[i][beg]) % M; 
            }
        }
    }
    int summ = 0;
    for (int beg = 0; beg <= n; beg++) summ = (summ + dp[0][beg]) % M;
    cout << summ << endl;
}