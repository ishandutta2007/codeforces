#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, mod = 998244353;
int a[maxn];
long long c[maxn][maxn], dp[maxn];
vector<pair<int, long long>> to[maxn];

int main() {
    int n; cin >> n;
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            c[i][j] = c[i - 1][j];
            if (j) (c[i][j] += c[i - 1][j - 1]) %= mod;
        }
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) if (a[i] > 0) {
        int k = a[i] + 1;
        for (int j = i + 1; j <= n; ++j) {
            int gap = j - i - 1;
            if (k - 2 >= maxn) continue;
            long long w = c[gap][k - 2];
            if (w) to[j].emplace_back(i, w);
        }
    }
    dp[0] = 1;
    // for (int i = 1; i <= n; ++i) {
        // cout << "i = " << i << endl;
        // for (auto j : to[i]) cout << "(" << j.first << " " << j.second << ") ";
        // cout << endl;
    // }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto j : to[i]) {
            (dp[i] += (j.second * dp[j.first - 1]) % mod) %= mod;
        } 
        (dp[i] += dp[i - 1]) %= mod;
    }
    --dp[n];
    if (dp[n] < 0) dp[n] += mod;
    cout << dp[n] << endl;
}