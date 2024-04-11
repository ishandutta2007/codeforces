#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, mt[maxn][maxn], x, bsl, bsm, bsu;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        x = 0;
        for (i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) x++;
        }

        if (x == 0) {
            cout << 1 << nl; continue;
        }

        if (k == 1) {
            cout << -1 << nl; continue;
        }

        bsl = 1; bsu = INF;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            // cout << bsm << ' ' << (x + bsm - 1) / bsm << ' ' << k - 1 << nl;
            if ((x + bsm - 1) / bsm <= k - 1) {
                bsu = bsm;
            } else {
                bsl = bsm + 1;
            }
        }

        cout << bsl << nl;
    }

    return 0;
}