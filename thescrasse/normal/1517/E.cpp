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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll ps1[maxn], ps2[maxn], tt, bsl, bsm, bsu;

ll rs1(ll l, ll r) {
    if (r > n) return INF;
    return ps1[r] - ps1[l - 1];
}

ll rs2(ll l, ll r) {
    if (r > n) return INF;
    if (l == 1) return ps2[r];
    return ps2[r] - ps2[l - 2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = 1; tt = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; tt += a[i];
        }
        tt = (tt - 1) / 2;

        for (i = 1; i <= n; i++) {
            ps1[i] = ps1[i - 1] + a[i];
        }

        ps2[1] = a[1];
        for (i = 2; i <= n; i++) {
            ps2[i] = ps2[i - 2] + a[i];
        }

        // begins with BB
        for (i = 3; i <= n; i++) {
            if (rs1(i, n) <= tt) res++;
        }
        // cout << res << nl;

        // begins with R, finishes with R
        for (i = 1; i <= n; i++) {
            bsl = -1; bsu = 100000010;
            while (bsl != bsu) {
                bsm = (bsl + bsu + 1) / 2;
                if (i + 2 * bsm <= n - 3 && rs1(1, i - 1) + rs2(i, i + 2 * bsm) + a[n] <= tt) {
                    bsl = bsm;
                } else {
                    bsu = bsm - 1;
                }
            }
            res += bsl + 1;
            // cout << "i, bsl = " << i _ bsl + 1 << nl;
        }
        // cout << res << nl;

        // begins with R, finishes with B
        for (i = 1; i <= n; i++) {
            bsl = -1; bsu = 100000010;
            while (bsl != bsu) {
                bsm = (bsl + bsu + 1) / 2;
                if (rs1(1, i - 1) + rs2(i, i + 2 * bsm) <= tt) {
                    bsl = bsm;
                } else {
                    bsu = bsm - 1;
                }
            }
            res += bsl + 1;
            // cout << "i, bsl = " << i _ bsl + 1 << nl;
        }
        // cout << res << nl;

        // begins with BR, finishes with R
        for (i = 2; i <= n; i++) {
            bsl = -1; bsu = 100000010;
            while (bsl != bsu) {
                bsm = (bsl + bsu + 1) / 2;
                if (i + 2 * bsm <= n - 3 && rs1(2, i - 1) + rs2(i, i + 2 * bsm) + a[n] <= tt) {
                    bsl = bsm;
                } else {
                    bsu = bsm - 1;
                }
            }
            res += bsl + 1;
            // cout << "i, bsl = " << i _ bsl + 1 << nl;
        }
        // cout << res << nl;

        // begins with BR, finishes with B
        for (i = 2; i <= n; i++) {
            bsl = -1; bsu = 100000010;
            while (bsl != bsu) {
                bsm = (bsl + bsu + 1) / 2;
                if (rs1(2, i - 1) + rs2(i, i + 2 * bsm) <= tt) {
                    bsl = bsm;
                } else {
                    bsu = bsm - 1;
                }
            }
            res += bsl + 1;
            // cout << "i, bsl = " << i _ bsl + 1 << nl;
        }
        // cout << res << nl;

        res %= mod;
        cout << res << nl;
        // cout << "---" << nl;
    }

    return 0;
}