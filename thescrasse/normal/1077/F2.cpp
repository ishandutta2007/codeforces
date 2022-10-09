// 1077F2
// somma max di x a[j] tali che per ogni segmento lungo k  stato scelto un j

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[5010], b, dp[5010][10010], v, x;

void upd(ll a, ll pos, ll k) {
    pos += n + 1;
    while (pos > 0) {
        dp[a][pos] = max(dp[a][pos], k);
        pos /= 2;
    }
}

ll rmq(ll a, ll l, ll r) {
    // cout << a << ' ' << l << ' ' << r << endl;
    l += n + 1; r += n + 1;
    ll res;
    res = -INF;
    while (l < r) {
        // cout << l << ' ' << r << endl;
        if (l % 2 == 1) {
            res = max(res, dp[a][l]); l++;
        }
        if (r % 2 == 0) {
            res = max(res, dp[a][r]); r--;
        }
        l /= 2; r /= 2;
    }
    if (l == r) {
        res = max(res, dp[a][l]);
    }

    // cout << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k >> x;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 0; i <= x; i++) {
        for (j = 1; j < 2 * n + 10; j++) {
            dp[i][j] = -INF;
        }
    }
    upd(0, 0, 0);

    for (i = 1; i <= x; i++) {
        for (j = 0; j <= n; j++) {
            if (i > j) {
                upd(i, j, -INF);
                continue;
            }
            // cout << "update" << endl;
            // cout << i << ' ' << j << endl;
            v = -INF;
            if (j > 0) {
                v = rmq(i - 1, max((ll)0, j - k), j - 1) + a[j];
            }
            // v = max(v, dp[i][j + n - 1]);
            upd(i, j, v);
            // cout << v << endl;
        }
    }

    /* for (i = 0; i <= x; i++) {
        for (j = 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << "| ";
        for (j = 0; j <= n; j++) {
            cout << dp[i][j + n + 1] << ' ';
        }
        cout << endl;
    } */

    res = rmq(x, max((ll)0, n - k + 1), n);
    if (res < 0) {
        res = -1;
    }

    cout << res;

    return 0;
}