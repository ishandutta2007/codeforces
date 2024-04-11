// 1344D
// Rsum Review

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)5e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], tt;

ll fl(ll a, ll b) {
    if (a >= 0) return a / b;
    else return (a - b + 1) / b;
}

ll bs_row(ll r, ll x) {
    ll bsl, bsm, bsu;
    bsl = 0; bsu = a[r];
    while (bsl != bsu) {
        bsm = fl(bsl + bsu + 1, 2);
        // cout << bsm _ a[r] - 3 * bsm * bsm + 3 * bsm - 1 << nl;
        if (a[r] - 3 * bsm * bsm + 3 * bsm - 1 >= x) {
            bsl = bsm;
        } else {
            bsu = bsm - 1;
        }
    }

    // cout << "r, x, bsl = " << r _ x _ bsl << nl;

    return bsl;
}

ll bs_col() {
    ll bsl, bsm, bsu, tt, i;
    bsl = -INF; bsu = INF;
    while (bsl != bsu) {
        bsm = fl(bsl + bsu + 1, 2); tt = 0;
        for (i = 1; i <= n; i++) tt += bs_row(i, bsm);
        // cout << "bsm, tt = " << bsm _ tt << nl;
        if (tt >= k) bsl = bsm;
        else bsu = bsm - 1;
    }

    return bsl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    m = bs_col();
    for (i = 1; i <= n; i++) {
        b[i] = bs_row(i, m); tt += b[i];
    }

    for (i = 1; i <= n; i++) {
        if (tt == k) break;
        if (a[i] - 3 * b[i] * b[i] + 3 * b[i] - 1 == m) {
            b[i]--; tt--;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << nl;

    return 0;
}