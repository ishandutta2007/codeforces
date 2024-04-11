#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), b(n + 1), c(n + 1), x(n + 1);
    rep(i, 1, n + 1) cin >> a[i] >> b[i] >> c[i];
    iota(x.begin(), x.end(), 0);
    rep(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        x[v] = max(u, x[v]);
    }
    vector<vector<ll>> dp(5050, vector<ll>(5050, -1));
    dp[0][k] = 0;
    rep(i, 0, n) {
        vector<int> cs;
        rep(j, 1, n + 1) if (x[j] == i + 1) cs.emplace_back(c[j]);
        sort(cs.begin(), cs.end(), greater<ll>());

        for (int j = 5000; j >= a[i + 1]; j--) {
            if (dp[i][j] != -1) {
                dp[i + 1][j + b[i + 1]] =
                    max(dp[i + 1][j + b[i + 1]], dp[i][j]);
            }
        }
        for (auto l : cs) {
            rep(j, 1, 5001) {
                if (dp[i + 1][j] != -1) {
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i + 1][j] + l);
                }
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}