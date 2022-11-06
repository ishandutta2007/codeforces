#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int dp[maxn], z[maxn][maxn];
vector<int> f[maxn];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (s[i - 1] == s[j - 1])
                z[i][j] = max(z[i][j], z[i - 1][j - 1] + 1);
        }
    } 
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a;
        for (int j = 0; j < i; ++j) {
            int diff = min(i - j, z[i][j]);
            dp[i] = min(dp[i], dp[i - diff] + b);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}