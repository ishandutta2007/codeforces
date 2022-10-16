#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, l, k; cin >> n >> l >> k;
    vector dp(n+1, vector<ll>(k+1));
    vector<int> d(n);
    vector<int> a(n);
    for (int& x : d) cin >> x;
    for (int& x : a) cin >> x;
    d.push_back(l);

    for (int i = n; i--; ) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 1e18;
            for (int t = i+1; t <= n && t - i - 1 <= j; ++t) {
                ckmin(dp[i][j], (ll)(d[t] - d[i]) * a[i] + dp[t][j-t+i+1]);
            }
        }

        // cout << dp[i][k] << '\n';
    }

    cout << dp[0][k] << '\n';
}