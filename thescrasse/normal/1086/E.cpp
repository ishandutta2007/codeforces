#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], dp[maxn][maxn], fn[maxn], c, cm;

struct fenwick {
    ll fn[maxn] = {0};

    void upd(ll p, ll x) {
        while (p < maxn) {
            fn[p] += x; p += (p & (-p));
        }
    }

    ll ps(ll p) {
        ll r = 0;
        while (p > 0) {
            r += fn[p]; p -= (p & (-p));
        }
        return r;
    }

    ll rs(ll l, ll r) {
        return ps(r) - ps(l - 1);
    }

    void clr() {
        ll i;
        for (i = 0; i < maxn; i++) fn[i] = 0;
    }
};

fenwick fu, fl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> mt[i][j];
        }
    }

    dp[0][0] = 1;
    for (i = 1; i <= n; i++) {
        dp[i][0] = (i * dp[i - 1][0]) % mod;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (j >= 2) dp[i][j] += ((j - 1) * dp[i - 1][j - 2]);
            dp[i][j] += ((i - j) * dp[i - 1][j - 1]);
            dp[i][j] %= mod;
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    fu.clr(); fl.clr();
    for (j = 1; j <= n; j++) {
        a = fl.rs(1, mt[1][j] - 1); b = mt[1][j] - a - 1;
        res += (b * dp[n - j][0]); res %= mod;
        fl.upd(mt[1][j], 1);
    }
    // cout << "res =" _ res << nl;

    for (i = 2; i <= n; i++) {
        res = (res * dp[n][n]) % mod;
        fu.clr(); fl.clr(); cm = 0; k = 0;
        for (j = 1; j <= n; j++) {
            // cout << "i, j =" _ i _ j << nf;
            if (fl.rs(mt[i - 1][j], mt[i - 1][j]) == 0) fu.upd(mt[i - 1][j], 1);
            a = fu.rs(1, mt[i][j] - 1); b = fl.rs(1, mt[i][j] - 1);
            c = mt[i][j] - a - b - 1;
            if (mt[i - 1][j] <= mt[i][j] - 1) a -= fu.rs(mt[i - 1][j], mt[i - 1][j]);
            cm += fl.rs(mt[i - 1][j], mt[i - 1][j]);

            /* for (i1 = 1; i1 <= n; i1++) cout << fu.rs(i1, i1) << ' ';
            cout << nl;
            for (i1 = 1; i1 <= n; i1++) cout << fl.rs(i1, i1) << ' ';
            cout << nl; */

            if (n + cm - 2 * j >= 0) k += (c * dp[n - j][n + cm - 2 * j]);
            if (n + cm - 2 * j + 1 >= 0) k += (a * dp[n - j][n + cm - 2 * j + 1]);
            k %= mod;
            // cout << "a, b, c, cm, k =" _ a _ b _ c _ cm _ k << nl;
            fl.upd(mt[i][j], 1);
            cm += fu.rs(mt[i][j], mt[i][j]);
            fu.upd(mt[i][j], -fu.rs(mt[i][j], mt[i][j]));
        }
        res += k;
        // cout << "res =" _ res << nl;
    }

    res %= mod;
    cout << res << nl;

    return 0;
}