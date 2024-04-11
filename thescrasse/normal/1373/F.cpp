// 1373F
// Network Coverage

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn], d[maxn], l, r;

ll md(ll x) {
    return x % n;
}

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
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
        }

        k = 0; flag[1] = 0; m = 0;
        while (m <= 3 * n) {
            // cout << "k = " << k << nl;
            c[k] = a[k]; d[k] = b[k];
            c[md(k + 1)] = a[md(k + 1)]; d[md(k + 1)] = b[md(k + 1)];
            c[k] = max((ll)0, c[k] - d[k]); flag[0] = 1;
            for (i = k + 1; i < k + n; i++) {
                m++;
                l = md(i); r = md(i + 1);
                if (r != k) {
                    c[r] = a[r]; d[r] = b[r];
                }
                // cout << "val " << l << ' ' << c[l] << ' ' << d[l] << nl;
                if (c[l] > d[l]) {
                    // cout << "err1 " << k << ' ' << l << nl;
                    k = l; flag[0] = 0; break;
                }
                c[r] = max((ll)0, c[r] - max((ll)0, d[l] - c[l])); c[l] = 0;
            }

            if (c[k] > 0) {
                flag[0] = 0;
                // cout << "err2 " << k << nl;
            }
            if (flag[0] == 1) {
                flag[1] = 1; break;
            }
        }

        if (flag[1] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}