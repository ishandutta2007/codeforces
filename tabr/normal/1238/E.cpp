#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> cnt(m, vector<ll>(m));
    vector<ll> dp(1 << m, 1e18);
    rep(i, 0, n - 1) {
        int a = s[i] - 'a', b = s[i + 1] - 'a';
        if (a == b)
            continue;
        cnt[b][a]++;
        cnt[a][b]++;
    }
    dp[0] = 0;
    rep(i, 0, 1 << m) {
        if (dp[i] == 1e18)
            continue;
        ll bitcnt = __builtin_popcount(i);
        rep(j, 0, m) {
            if (i & (1 << j))
                continue;
            ll res = dp[i];
            rep(k, 0, m) {
                if (j == k)
                    continue;
                if (i & (1 << k))
                    res += cnt[j][k] * bitcnt;
                else
                    res -= cnt[j][k] * bitcnt;
            }
            dp[i | (1 << j)] = min(dp[i | (1 << j)], res);
        }
    }
    cout << dp[(1 << m) - 1] << endl;
}