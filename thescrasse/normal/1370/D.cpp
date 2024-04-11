#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, bsl, bsu, bsm, dp[maxn], l, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    res = INF;

    if (k % 2 == 0) {
        l = 0; r = n - 1;
    } else {
        l = 0; r = n;
    }
    bsl = 0; bsu = 1000000010;
    while (bsl != bsu) {
        // cout << bsl << ' ' << bsu << nl;
        bsm = (bsl + bsu) / 2;
        for (i = 0; i < r; i++) {
            if (i <= 1) {
                if (a[i] <= bsm) dp[i] = 1;
                else if (i == 1 && dp[0] == 1) dp[i] = 1;
                else dp[i] = 0;
            } else {
                dp[i] = max(dp[i - 2] + (a[i] <= bsm), dp[i - 1]);
            }
        }

        /* for (i = 0; i < n; i++) cout << dp[i] << ' ';
        cout << nl;

        cout << dp[n - 1] << ' ' << (k + 1) / 2 << nl; */

        if (dp[r - 1] >= (k + 1) / 2) bsu = bsm;
        else bsl = bsm + 1;
    }

    res = min(res, bsl);
    // cout << res << nl;

    if (k % 2 == 0) {
        l = 1; r = n;
    } else {
        l = 1; r = n - 1;
    }
    bsl = 0; bsu = 1000000010;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        for (i = 1; i < r; i++) {
            if (i <= 2) {
                if (a[i] <= bsm) dp[i] = 1;
                else if (i == 2 && dp[1] == 1) dp[i] = 1;
                else dp[i] = 0;
            } else {
                dp[i] = max(dp[i - 2] + (a[i] <= bsm), dp[i - 1]);
            }
        }

        if (dp[r - 1] >= k / 2) bsu = bsm;
        else bsl = bsm + 1;
    }

    // cout << bsl << nl;
    res = min(res, bsl);

    cout << res;

    return 0;
}