#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d, e, f, r, x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        res = 0;
        cin >> a >> b >> c >> d >> e >> f;
        if (e > f) {
            swap(c, d); swap(e, f);
        }
        for (i = 0; i <= c; i++) {
            m = 0; x = c; y = d;
            if (i * e > a) continue;
            r = a - i * e; m += i; x -= i;
            k = min(d, r / f); m += k; y -= k;

            // cout << m << nl;

            // cout << x << ' ' << y << nl;
            r = b;
            if (r >= x * e) {
                r -= x * e; m += x;
                m += min(r / f, y);
            } else {
                m += r / e;
            }

            res = max(m, res);
            // cout << i << ' ' << m << nl;
        }

        cout << res << nl;
    }

    return 0;
}