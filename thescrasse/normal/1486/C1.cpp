#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, bsl, bsm, bsu;

ll ask(ll l, ll r) {
    ll x;
    if (l >= r) return -1;
    cout << "? " << l _ r << nf;
    cin >> x; return x;
}

ll clm(ll p) {
    cout << "! " << p << nf; exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;
    k = ask(1, n);
    if (ask(1, k) == k) {
        bsl = 1; bsu = k - 1;
        while (bsl != bsu) {
            bsm = (bsl + bsu + 1) / 2;
            if (ask(bsm, k) == k) bsl = bsm;
            else bsu = bsm - 1;
        }
    } else {
        bsl = k + 1; bsu = n;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            if (ask(k, bsm) == k) bsu = bsm;
            else bsl = bsm + 1;
        }
    }

    clm(bsl);

    return 0;
}