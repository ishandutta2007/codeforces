#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define y1 treapdidsu

ll i, i1, j, k, k1, t, n, m, res, flag, a, b, d[200010], s[200010], ps[200010], y, tot;
array<ll, 2> l1, l2;

ll bnm(ll x) {
    return (x * (x + 1)) / 2;
}

array<ll, 2> vl(ll x) {
    // cout << "x = " << x << endl;
    ll i, j, k, bsl, bsu, bsm;
    bsl = 0; bsu = n;
    while (bsl != bsu) {
        // cout << bsl << ' ' << bsu << endl;
        bsm = (bsl + bsu) / 2;
        if (s[bsm] > x) {
            bsu = bsm;
        } else {
            bsl = bsm + 1;
        }
    }
    bsl--;
    // cout << "f = " << x - s[bsl] + 1 << ' ' << bsl << endl;
    return {x - s[bsl] + 1, bsl};
}

ll src1(ll x) {
    ll a, b;
    // cout << "start src1 " << x << endl;
    ll i, j, k, bsl, bsu, bsm;
    bsl = s[x]; bsu = tot;
    if (x < n - 1) bsu = s[x + 1];
    while (bsl != bsu) {
        // cout << "src1: " << bsl << ' ' << bsu << endl;
        bsm = (bsl + bsu) / 2;
        a = vl(bsm)[0]; b = vl((bsm + y) % tot)[0];
        // cout << "a, b = " << a << ' ' << b << endl;
        if (a > b) {
            bsu = bsm;
        } else {
            bsl = bsm + 1;
        }
    }
    if (bsl == tot) {
        bsl = tot - 1;
    } else if (bsl == s[x + 1]) {
        bsl--;
    }
    // cout << "bsl = " << bsl << endl;
    return bsl;
}

ll rs(ll l, ll r) {
    if (l == 0) return ps[r];
    return ps[r] - ps[l - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> y;
    for (i = 0; i < n; i++) {
        cin >> d[i]; tot += d[i];
    }

    s[0] = 0; ps[0] = bnm(d[0]);
    for (i = 1; i < n; i++) {
        s[i] = s[i - 1] + d[i - 1];
        ps[i] = ps[i - 1] + bnm(d[i]);
        // cout << "init " << i << ' ' << s[i] << ' ' << ps[i] << endl;
    }

    res = 0;
    for (i = 0; i < n; i++) {
        k = src1(i); l1 = vl(k); l2 = vl((k + y + tot - 1) % tot);
        if (k + y - 1 < tot) {
            if (l1[1] == l2[1]) {
                j = bnm(l2[0]) - bnm(l1[0] - 1); // cout << j << endl;
            } else {
                j = rs(l1[1] + 1, l2[1] - 1); // cout << j << endl;
                j += bnm(l2[0]); // cout << j << endl;
                j += bnm(d[l1[1]]); // cout << j << endl;
                j -= bnm(l1[0] - 1); // cout << j << endl;
            }
        } else {
            j = rs(l1[1] + 1, n - 1); // cout << j << endl;
            if (l2[1] > 0) j += rs(0, l2[1] - 1); // cout << j << endl;
            j += bnm(d[l1[1]]); // cout << j << endl;
            j -= bnm(l1[0] - 1); // cout << j << endl;
            j += bnm(l2[0]); // cout << j << endl;
        }
        // cout << endl;
        res = max(res, j);
        // cout << i << ' ' << j << ' ' << k << ' ' << l1[0] << ' ' << l1[1] << ' ' << l2[0] << ' ' << l2[1] << endl << endl;
    }

    cout << res;

    return 0;
}