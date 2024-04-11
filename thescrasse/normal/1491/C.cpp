#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p, jm[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) jm[i] = i + 1;

        m = 1;
        while (m <= n && a[m] == 1) m++;
        while (m <= n) {
            if (a[m] > 5000) {
                res += a[m] - 5000; a[m] = 5000;
            }

            p = m; k = INF;
            while (p <= n) {
                // cout << "p = " << p << nl;
                if (a[p] == 1) {
                    k = min(k, p); p = jm[p];
                } else {
                    a[p]--;
                    for (i = k; i < p; i++) {
                        if (jm[i] == p) break;
                        jm[i] = p;
                        // cout << "jm " << i _ p << nl;
                    }
                    p += a[p] + 1; k = INF;
                }
            }
            // cout << "k = " << k << nl;
            for (i = k; i <= n; i++) {
                if (jm[i] == n + 1) break;
                jm[i] = n + 1;
                // cout << "jm " << i _ n + 1 << nl;
            }
            res++;
            // cout << "res = " << res << nl;

            while (m <= n && a[m] == 1) m++;

            // cout << "m = " << m << nf;

            /* for (i = 1; i <= n; i++) cout << a[i] << ' ';
            cout << nl; */
        }

        cout << res << nl;
    }

    return 0;
}