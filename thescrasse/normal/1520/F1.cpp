#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 10010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll fn[maxn], bsl, bsm, bsu;

ll ask(ll l, ll r) {
    ll x;
    cout << "? " << l _ r << nf;
    cin >> x; return x;
}

ll clm(ll x) {
    ll y;
    cout << "! " << x << nf;
    if (t == 0) exit(0);
    cin >> y; return y;
}

void upd(ll p, ll x) {
    while (p <= n) {
        fn[p] += x;
        p += (p & (-p));
    }
}

ll ps(ll p) {
    ll r = 0;
    while (p >= 1) {
        r += fn[p];
        p -= (p & (-p));
    }
    return r;
}

ll rs(ll l, ll r) {
    return ps(r) - ps(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> t >> k; t = 0;

    bsl = 1; bsu = n;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        if (ask(1, bsm) <= bsm - k) bsu = bsm;
        else bsl = bsm + 1;
    }

    k = clm(bsl);

    return 0;
}