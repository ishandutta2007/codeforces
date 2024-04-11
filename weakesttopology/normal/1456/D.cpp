#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
constexpr int nmax = 5000;
ll dp[nmax][nmax];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    vector<ll> t(n), x(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = abs(x[i]) + abs(x[i] - x[0]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        // leave clone where it is
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] <= t[i]) {
                chmin(dp[i + 1][j], t[i] + abs(x[i] - x[i + 1]));
            }
        }
        if (dp[i][i] <= t[i]) {
            // kill current cake with clone and move it
            for (int j = i + 1; j < n; ++j) {
                chmin(dp[i + 1][j], max(t[i], dp[i][i] + abs(x[i] - x[j])) + abs(x[j] - x[i + 1]));
            }
        }
        // kill next cake with clone
        if (dp[i][i + 1] <= t[i]) {
            for (int j = i + 2; j < n; ++j) {
                chmin(dp[i + 2][j], max(t[i] + abs(x[i] - x[j]), t[i + 1]) + abs(x[j] - x[i + 2]));
            }
        }
    }
    bool good = dp[n - 1][n - 1] <= t[n - 1] || (n > 1 && dp[n - 2][n - 1] <= t[n - 2]);
    cout << (good ? "YES" : "NO") << endl;
    exit(0);
}