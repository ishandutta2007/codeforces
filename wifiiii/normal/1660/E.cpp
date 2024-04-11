#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        vector<vector<vector<int>>> dp(11, vector<vector<int>>(n, vector<int>(n)));
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                dp[0][i][j] = c == '1';
                sum += c == '1';
            }
        }
        for(int i = 1; i <= 10; ++i) {
            int s = 1 << (i - 1);
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][(j + s) % n][(k + s) % n];
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int tmp = 0;
                for(int k = 0; k <= 10; ++k) {
                    if(n >> k & 1) {
                        tmp += dp[k][i][j];
                        i = (i + (1 << k)) % n;
                        j = (j + (1 << k)) % n;
                    }
                }
                mx = max(mx, tmp);
            }
        }
        cout << (n - mx) + (sum - mx) << '\n';
    }
}