#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

    cin >> n >> m;

    ll mxn = max(n, m);

    auto fxp = [&](ll b, ll e) {
        ll r = 1, k = b;
        while (e != 0) {
            if (e % 2) r = (r * k) % mod;
            k = (k * k) % mod; e /= 2;
        }
        return r;
    };

    auto inv = [&](ll x) {
        return fxp(x, mod - 2);
    };

    vector<ll> fc(mxn + 2, 1), nv(mxn + 2, 1);
    for (i = 1; i <= mxn; i++) fc[i] = (i * fc[i - 1]) % mod;
    nv[mxn] = inv(fc[mxn]);
    for (i = mxn - 1; i >= 1; i--) nv[i] = ((i + 1) * nv[i + 1]) % mod;

    auto bnm = [&](ll a, ll b) {
        if (a < b || b < 0) return (ll)0;
        ll r = (fc[a] * nv[b]) % mod;
        r = (r * nv[a - b]) % mod;
        return r;
    };

    vector<vector<ll>> pw(mxn + 2, vector<ll>(mxn + 2, 1));
    for (i = 0; i <= mxn; i++) {
        for (j = 1; j <= mxn; j++) pw[i][j] = (i * pw[i][j - 1]) % mod;
    }

    vector<vector<ll>> dp(mxn + 2, vector<ll>(mxn + 2, 0));
    dp[0][0] = 1;

    auto ways = [&](ll i, ll j, ll k) {
        if (i == k) return (pw[j][k] - pw[j - 1][k] + mod) % mod;
        else return (pw[i - 1][k] * bnm(i, k)) % mod;
    };

    res = 0;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            for (k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][max((ll)0, j - i + 1)] * ways(i, j, k)) % mod;
                // cout << "dp" _ i _ j _ k _ ways(i, j, k) _ bnm(i, k) _ dp[i][j] << nf;
            }
            if (i == n) res = (res + dp[i][j]) % mod;
        }
    }

    auto dbg = [&]() {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << nl;
        }
    };

    // dbg();

    cout << res << nl;

    return 0;
}