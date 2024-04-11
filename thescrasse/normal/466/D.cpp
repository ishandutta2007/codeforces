// 466D
// Increase Sequence

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag, a[2010], b, h, d[2010], c, mod;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> n >> h;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; a[i] = h - a[i];
    }
    a[0] = 0; a[n + 1] = 0; n += 2;

    for (i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    res = 1; c = 0; flag = 1;
    for (i = 1; i < n; i++) {
        if (d[i] < -1 || d[i] > 1 || c < 0) flag = 0;
        if (d[i] == 0) res = (res * (c + 1)) % mod;
        if (d[i] == -1) res = (res * c) % mod;
        c += d[i];
    }

    if (flag == 0) {
        cout << 0;
    } else {
        cout << res;
    }

    return 0;
}