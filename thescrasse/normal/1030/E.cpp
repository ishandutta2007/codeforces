// 1030E
// numero di intervalli tali che cambiando la posizione dei bit si pu ottenere xor = 0

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[300010], b, dp[300010], x, s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        a[i] = __builtin_popcountll(x);
    }

    dp[0] = 0; res = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = i - dp[i - 1] - 1;
        }
        res += dp[i];
    }

    for (i = 1; i <= n; i++) {
        s = 0; m = 0;
        for (j = i; j <= min(n, i + 65); j++) {
            s += a[j]; m = max(m, a[j]);
            if (2 * m > s && s % 2 == 0) {
                res--;
            }
        }
    }

    cout << res;

    return 0;
}