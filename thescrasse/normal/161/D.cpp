// 161D
// numero percorsi lunghi esattamente k in un tree

#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, dp[510][50010];
vector<pair<int, int>> el;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        el.push_back({a, b});
    }

    for (i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (j = 1; j <= k; j++) {
        for (auto u : el) {
            a = u.first;
            b = u.second;
            dp[j][a] += dp[j - 1][b];
            dp[j][b] += dp[j - 1][a];
        }
        if (j == 2) {
            for (i = 1; i <= n; i++) {
                dp[j][i] -= (dp[j - 2][i] * dp[1][i]);
            }
        }
        if (j >= 3) {
            for (i = 1; i <= n; i++) {
                dp[j][i] -= (dp[j - 2][i] * (dp[1][i] - 1));
            }
        }
    }

    for (i = 1; i <= n; i++) {
        res += dp[k][i];
    }
    res /= 2;
    cout << res;

    return 0;
}