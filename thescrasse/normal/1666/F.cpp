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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll i, i1, j, k, k1, t, n, m, res, b;
        vector<ll> flag(10, 0);

        cin >> n;
        vector<ll> a(n + 1, 0);
        for (i = 1; i <= n; i++) cin >> a[n - i + 1];

        ll mxn = 3 * n;

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

        auto fcs = [&](ll x) {
            if (x < 0) return (ll)0;
            return fc[x];
        };

        auto nvs = [&](ll x) {
            if (x < 0) return (ll)0;
            return nv[x];
        };

        auto bnm = [&](ll a, ll b) {
            if (a < b || b < 0) return (ll)0;
            ll r = (fc[a] * nv[b]) % mod;
            r = (r * nv[a - b]) % mod;
            return r;
        };

        vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));
        dp[0][0] = 1;

        auto w1 = [&](ll i, ll j, ll k) {
            // cout << i _ j _ k _ 2 * j - (i - k) + (k - 2) + (j == n / 2) _ 2 * j - (i - k) - 2 + (j == n / 2) << nl;
            return (bnm(2 * j - (i - k) + (k - 2) - (k - 1) + (j == n / 2), 2 * j - (i - k) - 2 - (k - 1) + (j == n / 2))) % mod;
        };

        // j - 1 spazi
        // (i - k) - j spazi occupati
        // 2 * j + k - i - 1

        auto w2 = [&](ll i, ll j, ll k) {
            if (k == 1) return (ll)1;
            // cout << i _ j _ k _ 2 * (j - 1) - (i - k) + (k - 3) _ 2 * (j - 1) - (i - k) - 2 << nl;
            return (bnm(2 * (j - 1) - (i - k) + (k - 3) - (k - 2), 2 * (j - 1) - (i - k) - 2 - (k - 2))) % mod;
        };

        for (i = 1; i <= n; i++) {
            k = 1;
            while (i < n && a[i] == a[i + 1]) k++, i++;
            for (j = 1; j <= i; j++) {
                dp[i][j] = (dp[i][j] + w1(i, j, k) * dp[i - k][j] + w2(i, j, k) * dp[i - k][j - 1]) % mod;
                // cout << "dp" _ i _ j _ k _ w1(i, j, k) _ w2(i, j, k) << nl;
            }
        }

        auto dbg = [&]() {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    cout << dp[i][j] << ' ';
                }
                cout << nl;
            }
        };

        // dbg();

        cout << dp[n][n / 2] << nl;
    }

    return 0;
}