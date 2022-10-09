#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010
#define sq1 276
#define sq2 512
#define sq3 1091

struct sqdc {
    ll fn[301010] = {}, fns[587] = {};

    void upd_p(int p, ll x) {
        fn[p] += x; fns[p >> 9] += x;
    }

    ll rs_p(int p) {
        return (fn[p] + fns[p >> 9]);
    }

    void upd_r(int l, int r, ll x) {
        int lq, rq, i;
        if (l > r) return;
        lq = (l + sq2 - 1) >> 9; rq = (r - sq2) >> 9;
        for (i = lq; i <= rq; i++) fns[i] += x;
        if (lq > rq) {
            for (i = l; i <= r; i++) fn[i] += x;
        } else {
            for (i = l; i <= sq2 * lq - 1; i++) fn[i] += x;
            for (i = sq2 * (rq + 1); i <= r; i++) fn[i] += x;
        }
    }

    ll rs_r(int l, int r) {
        int lq, rq, i;
        ll rs = 0;
        if (l > r) return 0;
        lq = (l + sq2 - 1) >> 9; rq = (r - sq2) >> 9;
        for (i = lq; i <= rq; i++) rs += fns[i];
        if (lq > rq) {
            for (i = l; i <= r; i++) rs += fn[i];
        } else {
            for (i = l; i <= sq2 * lq - 1; i++) rs += fn[i];
            for (i = sq2 * (rq + 1); i <= r; i++) rs += fn[i];
        }
        return rs;
    }
};

int i, i1, j, k, k1, t, n, m, flag[10], a[200010], b;
int l, r;
ll res, ps[200010], rss[200010];
set<int> sm;
sqdc sql, sqr;
long double cl;

void naive() {
    ll i, rs = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i - 1; j++) {
            rs += (a[i] % a[j]); rs += (a[j] % a[i]);
        }
        cout << rs << ' ';
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    // cl = -clock();

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; ps[i] = ps[i - 1] + a[i];
    }

    for (i = 1; i <= n; i++) {
        res += ((i - 1) * (ll)a[i]) + ps[i - 1];
        // cout << "res1 = " << res << nl;
        if (a[i] <= sq3) {
            for (j = 1; j <= i - 1; j++) {
                res -= ((ll)a[j] * (a[i] / a[j]) + (ll)a[i] * (a[j] / a[i]));
            }
            sm.insert(a[i]);
        } else {
            res -= (a[i] * sql.rs_r(1, a[i]));
            // cout << "sql = " << a[i] * sql.rs_r(1, a[i]) << nl;
            for (j = 1; j <= sq1; j++) {
                l = (a[i] / (j + 1)) + 1; r = a[i] / j;
                if (l > r) continue;
                res -= (j * (sqr.rs_p(r) - sqr.rs_p(l - 1)));
                /* if (sqr.rs_p(r) - sqr.rs_p(l - 1) != 0) {
                    cout << "sqr = " << j _ l _ r _ sqr.rs_p(r) - sqr.rs_p(l - 1) << nl;
                } */
            }
            for (auto u : sm) {
                // u / a[i] (?)
                if (a[i] / u <= sq1) break;
                res -= ((ll)u * (a[i] / u));
            }
        }

        for (j = 1; j <= sq1; j++) {
            l = (a[i] / (j + 1)) + 1; r = a[i] / j;
            if (l > r) continue;
            sql.upd_p(l, j); sql.upd_p(r + 1, -j);
        }
        sqr.upd_r(a[i], maxn - 1, a[i]);

        // cout << "res2 = " << res << nl;
        rss[i] = res;
    }

    for (i = 1; i <= n; i++) cout << rss[i] << ' ';
    cout << nl;

    // naive();

    /* cl += clock();
    cl /= CLOCKS_PER_SEC;
    cout << fixed << setprecision(20);
    cout << cl << nl; */

    return 0;
}