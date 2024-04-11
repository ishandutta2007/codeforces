// 983B
// piramide xor

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[5010], b, dp[5010][5010], l, r, xp[5010][5010], q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            l = i;
            r = i + j;
            if (l == r) {
                xp[l][r] = a[l];
            } else {
                xp[l][r] = (xp[l][r - 1]) ^ (xp[l + 1][r]);
            }
        }
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            l = i;
            r = i + j;
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max({xp[l][r], dp[l][r - 1], dp[l + 1][r]});
            }
        }
    }

    cin >> q;
    for (i = 0; i < q; i++) {
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << endl;
    }

    return 0;
}