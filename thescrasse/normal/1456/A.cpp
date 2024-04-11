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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn], p, x, y;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> p >> k >> s >> x >> y;
        for (i = p; i <= n; i++) a[i - p + 1] = (s[i - 1] == '1');
        n = n - p + 1;
        for (i = 1; i <= n; i++) {
            if (a[i] == 0) f[i % k] += x;
        }

        /* for (i = 1; i <= n; i++) {
            cout << i % k << ' ' << f[i % k] << nl;
        } */

        res = INF;
        for (i = 1; i <= n; i++) {
            // cout << i << ' ' << f[i % k] << ' ' << x * i << nl;
            res = min(res, f[i % k] + (y * (i - 1)));
            f[i % k] -= x * (a[i] == 0);
        }

        cout << res << nl;
    }

    return 0;
}