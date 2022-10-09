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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn][2], b;
ll ps[maxn][2], mx;

ll bnm(ll x) {
    return ((x * (x - 1)) / 2);
}

ll calc(ll i, ll k, ll d) {
    // cout << "calc" _ i _ k _ d << nl;
    ll j, f, r = 0, p, cr, lll, rrr;
    if (d == 1) {
        i = n - i + 1;
    }

    if (k < n - i + 1) {
        lll = i; rrr = i + k - 1;
    } else if (k < 2 * (n - i + 1)) {
        lll = i; rrr = n;
    } else if (k < (n - i + 1) + (n - 1)) {
        lll = i - (k - (2 * (n - i + 1)) - 1); rrr = n;
    } else {
        lll = 1; rrr = n;
    }
    r += (ps[rrr][d] - ps[lll - 1][d]);

    // cout << "partial" _ r << nl;

    if (k < n - i + 1) {
        r += bnm(k); return r;
    }

    k -= (n - i + 1); r += bnm(n - i + 1);
    // cout << "partial" _ r << nl;

    if (k < n - i) {
        r += (2 * bnm(k + 1)); return r;
    }

    k -= (n - i); r += (2 * bnm(n - i + 1));
    cr = 2 * (n - i);
    // cout << "partial" _ r << nl;

    if (k < i - 1) {
        r += (bnm(cr + k + 1) - bnm(cr + 1)); return r;
    }

    k -= (i - 1); r += (bnm(cr + i) - bnm(cr + 1));
    // cout << "partial" _ r << nl;

    if (n == 1) {
        r += k; return r;
    }

    f = k / (n - 1);
    r += (2 * f * bnm(n));
    k %= (n - 1);
    r += (2 * bnm(k + 1));
    // cout << "partial" _ r << nl;
    return r;
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
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> a[i][0]; a[n - i + 1][1] = a[i][0];
        }

        for (i = 1; i <= n; i++) {
            ps[i][0] = ps[i - 1][0] + a[i][0];
            ps[i][1] = ps[i - 1][1] + a[i][1];
        }

        res = 0;

        for (i = 1; i <= n; i++) res = max({res, calc(i, k, 0), calc(i, k, 1)});

        cout << res << nl;
    }

    return 0;
}