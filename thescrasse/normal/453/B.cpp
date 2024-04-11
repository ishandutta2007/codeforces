// 453B
// Little Pony and Harmony Chest

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 110
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn][65546], pf[68], s, x, pv[maxn][65546];
vector<ll> r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll pl[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    for (i = 1; i <= 58; i++) {
        pf[i] = 0;
        for (j = 0; j < 16; j++) {
            if (i % pl[j] == 0) {
                pf[i] += (1 << j);
            }
        }
    }

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j < (1 << 16); j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 58; j++) {
            x = (~pf[j]) & ((1 << 16) - 1);
            // cout << i << ' ' << j << ' ' << x << endl;
            for (s = x;; s = (s - 1) & x) {
                if (dp[i - 1][s] + abs(a[i] - j) < dp[i][s | pf[j]]) {
                    dp[i][s | pf[j]] = dp[i - 1][s] + abs(a[i] - j);
                    pv[i][s | pf[j]] = j;
                }
                if (s == 0) break;
            }
        }
    }

    res = INF; m = -1;
    for (i = 0; i < (1 << 16); i++) {
        /* if (dp[n][i] != INF) {
            cout << i << ' ' << dp[1][i] << endl;
        } */
        if (dp[n][i] < res) {
            res = dp[n][i]; m = i;
        }
    }

    for (i = n; i > 0; i--) {
        // cout << m << endl;
        r.push_back(pv[i][m]);
        m ^= pf[pv[i][m]];
    }

    reverse(r.begin(), r.end());
    for (auto u : r) {
        cout << u << ' ';
    }

    return 0;
}