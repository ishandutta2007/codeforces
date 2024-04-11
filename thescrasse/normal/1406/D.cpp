#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], q, l, r, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; k = 0;
    for (i = 0; i < n; i++) {
        cin >> b[i];
        if (i == 0) a[i] = b[i];
        else a[i] = b[i] - b[i - 1];
        if (i > 0 && a[i] > 0) k += a[i];
    }
    a[n] = -b[n - 1];

    res = k + a[0] + 1;
    if (res < 0) res--;
    res /= 2;

    cout << res << nl;

    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        l--; r--;
        if (l != 0 && a[l] > 0) k -= a[l];
        if (r + 1 != n && a[r + 1] > 0) k -= a[r + 1];
        a[l] += x; a[r + 1] -= x;
        if (l != 0 && a[l] > 0) k += a[l];
        if (r + 1 != n && a[r + 1] > 0) k += a[r + 1];

        /* for (i = 0; i <= n; i++) cout << a[i] << ' ';
        cout << nl; */

        res = k + a[0] + 1;
        if (res < 0) res--;
        res /= 2;

        cout << res << nl;
    }

    return 0;
}