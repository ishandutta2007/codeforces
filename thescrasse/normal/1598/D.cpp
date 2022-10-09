#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll f[maxn], g[maxn];

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
            cin >> a[i] >> b[i];
            f[a[i]]++; g[b[i]]++;
        }

        /* for (i = 1; i <= n; i++) {
            if (f[a[i]] <= 0) continue;
            k = f[a[i]]; f[a[i]] *= -1;
            res += ((n - k) * ((k * (k - 1)) / 2));
            res += ((k * (k - 1) * (k - 2)) / 6);
        }

        for (i = 1; i <= n; i++) {
            if (g[b[i]] <= 0) continue;
            k = g[b[i]]; g[b[i]] *= -1;
            res += ((n - k) * ((k * (k - 1)) / 2));
            res += ((k * (k - 1) * (k - 2)) / 6);
        }

        cout << "res =" _ res << nl;

        for (i = 1; i <= n; i++) {
            f[a[i]] = abs(f[a[i]]); g[b[i]] = abs(g[b[i]]);
        } */

        for (i = 1; i <= n; i++) {
            res += max((ll)0, ((f[a[i]] - 1) * (g[b[i]] - 1)));
        }

        // cout << "res =" _ res << nl;

        res = ((n * (n - 1) * (n - 2)) / 6) - res;
        cout << res << nl;

        for (i = 1; i <= n; i++) {
            f[a[i]] = 0; g[b[i]] = 0;
        }
    }

    return 0;
}