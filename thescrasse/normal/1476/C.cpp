#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll c[maxn], x[maxn], y[maxn], z[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }

        for (i = 1; i <= n; i++) {
            if (i == n) x[i] = 0;
            else x[i] = abs(a[i + 1] - b[i + 1]);
            y[i] = c[i] - x[i] - 1;
        }

        for (i = 2; i <= n; i++) y[i] += y[i - 1] + 2;
        for (i = 1; i <= n; i++) z[i] = x[i] + y[i];
        z[n + 1] = 0;
        for (i = n; i >= 1; i--) {
            if (x[i] != 0) z[i] = max(z[i], z[i + 1]);
        }

        /* for (i = 1; i <= n; i++) {
            cout << i _ x[i] _ y[i] _ z[i] << nl;
        } */

        res = 0;
        for (i = 1; i <= n; i++) {
            res = max(res, x[i] - y[i] + z[i + 1]);
        }

        cout << res << nl;
    }

    return 0;
}