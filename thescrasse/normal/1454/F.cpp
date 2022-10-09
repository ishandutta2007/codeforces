#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, l, sp[20][maxn][2], p2[maxn];
ll bsl, bsm, bsu;

ll rmq(ll ty, ll l, ll r) {
    // cout << "rmq " << ty _ l _ r << nl;
    ll k = p2[r - l + 1];
    if (ty == 0) return min(sp[k][l][0], sp[k][r - (1 << k) + 1][0]);
    else return max(sp[k][l][1], sp[k][r - (1 << k) + 1][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    p2[1] = 0;
    for (i = 2; i < maxn; i++) p2[i] = p2[i / 2] + 1;

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (j = 1; j <= n; j++) {
            for (k = 0; k < 2; k++) {
                sp[0][j][k] = a[j];
            }
        }

        for (i = 1; i <= 20; i++) {
            for (j = 1; j <= n - (1 << i) + 1; j++) {
                sp[i][j][0] = min(sp[i - 1][j][0], sp[i - 1][j + (1 << (i - 1))][0]);
                sp[i][j][1] = max(sp[i - 1][j][1], sp[i - 1][j + (1 << (i - 1))][1]);
            }
        }

        /* for (i = 1; i <= 20; i++) {
            for (j = 1; j <= n; j++) {
                for (k = 0; k < 2; k++) {
                    cout << i _ j _ k _ sp[i][j][k] << nl;
                }
            }
        } */

        flag[0] = 0;
        for (l = 2; l <= n - 1; l++) {
            m = rmq(1, 1, l - 1);
            // cout << "l, m = " << l _ m << nl;
            bsl = l; bsu = n;
            while (bsl != bsu) {
                bsm = (bsl + bsu) / 2;
                // cout << bsl _ bsu _ bsm _ rmq(0, l, bsm) _ rmq(1, bsm + 1, n) << nl;
                if (rmq(0, l, bsm) < m) {
                    bsu = bsm;
                } else if (rmq(0, l, bsm) > m || rmq(1, bsm + 1, n) > m) {
                    bsl = bsm + 1;
                } else if (rmq(1, bsm + 1, n) < m) {
                    bsu = bsm;
                } else {
                    cout << "YES" << nl;
                    cout << l - 1 << ' ' << bsm - l + 1 << ' ' << n - bsm << nl;
                    flag[0] = 1; break;
                }
            }
            if (flag[0] == 1) break;
        }

        if (flag[0] == 0) cout << "NO" << nl;
    }

    return 0;
}