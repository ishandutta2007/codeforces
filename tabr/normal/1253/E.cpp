#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;
    vector<int> x(n), s(n);
    rep(i, 0, n) cin >> x[i] >> s[i];
    vector<int> dp(m + 1);
    rep(i, 1, m + 1) {
        dp[i] = i;
        rep(j, 0, n) if (x[j] - s[j] <= i && i <= x[j] + s[j]) {
            dp[i] = min(dp[i], dp[i - 1]);
        }
        else if (x[j] + s[j] < i) {
            int u = i - x[j] - s[j];
            dp[i] = min(dp[i], u + dp[max(0, x[j] - s[j] - u - 1)]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}