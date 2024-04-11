#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, l, r, fc[maxn], nv[maxn];

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2) {
        r = fxp(b, e - 1); return (b * r) % mod;
    } else {
        r = fxp(b, e / 2); return (r * r) % mod;
    }
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

ll bnm(ll a, ll b) {
    if (a < b) return 0;
    ll r = fc[a];
    r *= nv[b]; r %= mod;
    r *= nv[a - b]; r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    cin >> t;
    while (t--) {
        cin >> n >> m >> k; res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        /* for (i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << nl; */

        l = 1; r = 1;
        while (true) {
            if (r != n && a[r + 1] - a[l] <= k) {
                r++;
            } else if (l != n + 1) {
                // cout << "l, r = " << l _ r << nl;
                res += bnm(r - l, m - 1); res %= mod; l++;
            } else {
                break;
            }
        }

        cout << res << nl;
    }

    return 0;
}