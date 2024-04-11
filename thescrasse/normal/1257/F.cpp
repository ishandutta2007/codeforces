// 1257F
// Make Them Similar

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, res, flag[10], a[maxn];
array<ll, 100> b;
map<array<ll, 100>, ll> m[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < 100; i++) b[i] = 0;

    for (i = 0; i < (1 << 15); i++) {
        // if (i < 16) cout << "i = " << i << nl;
        for (j = 0; j < n; j++) {
            b[j] = (a[j] % (1 << 15)) ^ i;
            if (b[j] != 0) b[j] = __builtin_popcountll(b[j]);
            // cout << j << ' ' << b[j] << nl;
        }
        m[0][b] = i + 1;

        for (j = 0; j < n; j++) {
            b[j] = (a[j] >> 15) ^ i;
            if (b[j] != 0) b[j] = __builtin_popcountll(b[j]);
            if (j != 0) b[j] -= b[0];
            // cout << j << ' ' << b[j] << nl;
        }
        b[0] = 0; m[1][b] = i + 1;
    }

    for (auto u : m[0]) {
        b = u.first; k = u.second;
        // cout << k << nl;
        /* for (i = 0; i < n; i++) {
            cout << i << ' ' << b[i] << nl;
        } */
        for (i = 0; i < n; i++) {
            b[i] *= -1;
            if (i != 0) b[i] -= b[0];
            // cout << i << ' ' << b[i] << nl;
        }
        b[0] = 0; j = m[1][b];
        if (j != 0) {
            cout << (ll)(1 << 15) * (j - 1) + (k - 1);
            return 0;
        }
    }

    cout << -1;

    return 0;
}