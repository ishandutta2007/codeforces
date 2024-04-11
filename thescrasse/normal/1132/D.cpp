// 1132D
// Stressful Training

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], ps[maxn], bsl, bsu, bsm;

bool solve(ll x) {
    // cout << "x = " << x << nl;
    ll m, p, l;
    m = 0;
    for (i = 0; i <= k; i++) ps[i] = 0;
    for (i = 0; i < n; i++) {
        // cout << "i = " << i << nl;
        if (x >= b[i]) {
            l = 0; p = a[i];
            while (true) {
                // cout << "p = " << p << nl;
                if (l >= k - 1) break;
                if (m >= k) return false;
                if (p < b[i]) {
                    m++; ps[l]++; l++; p += (x - b[i]);
                } else {
                    l += (p / b[i]); p %= b[i];
                }
            }
        } else {
            p = a[i];
            if (x == 0) {
                if ((k - 1) * b[i] - p > 0) return false;
                else continue;
            }
            j = ((k - 1) * b[i] - p + x - 1) / x;
            if (j >= k) return false;
            // cout << "j = " << j << nl;
            for (i1 = k - 1; i1 > k - j - 1; i1--) {
                ps[i1]++; m++;
            }
            if (m >= k) return false;
        }
    }

    for (i = 0; i < k; i++) {
        if (i != 0) ps[i] += ps[i - 1];
        // cout << i << ' ' << ps[i] << nl;
        if (ps[i] > i + 1) return false;
    }

    return true;
}

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
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    bsl = 0; bsu = INF;
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        if (solve(bsm)) {
            bsu = bsm;
        } else {
            bsl = bsm + 1;
        }
    }

    if (bsl == INF) cout << -1;
    else cout << bsl;

    return 0;
}