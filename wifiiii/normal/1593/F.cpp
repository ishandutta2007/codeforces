#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(a, vector<ll>(b, -1))));
        dp[0][0][0][0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < a; ++k) {
                    for(int r = 0; r < b; ++r) {
                        if(dp[i][j][k][r] != -1) {
                            dp[i + 1][j + 1][(k * 10 + s[i] - '0') % a][r] = dp[i][j][k][r];
                            dp[i + 1][j][k][(r * 10 + s[i] - '0') % b] = dp[i][j][k][r] | (1ll << i);
                        }
                    }
                }
            }
        }
        int mi = 1e9;
        ll msk = -1;
        for(int i = 1; i < n; ++i) {
            if(dp[n][i][0][0] != -1 && abs(2 * i - n) < abs(2 * mi - n)) {
                mi = i;
                msk = dp[n][i][0][0];
            }
        }
        if(mi == 1e9) cout << -1 << endl;
        else {
            string ans(n, 'R');
            for(int i = 0; i < n; ++i) {
                if(msk >> i & 1) ans[i] = 'B';
            }
            cout << ans << '\n';
        }
    }
}