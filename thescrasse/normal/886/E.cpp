// 886E
// Maximum Element

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn];
ll fc[maxn], nv[maxn];

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

void fx(ll &x) {
    x %= mod; x += mod; x %= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i <= n; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    dp[0] = 1; dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = (i * dp[i - 1]) % mod;
        if (i <= k) continue;
        m = fc[i - 1] * nv[i - k - 1]; fx(m);
        m *= dp[i - k - 1]; fx(m);
        dp[i] -= m; fx(dp[i]);
        // cout << i << ' ' << dp[i] << nl;
    }
    // cout << nl;

    for (i = 1; i <= n - k; i++) {
        m = fc[n - 1];
        m *= (n - i - k); fx(m);
        m *= nv[i - 1]; fx(m);
        m *= dp[i - 1]; fx(m);
        m *= inv(i + k); fx(m);
        res += m; fx(res);
        // cout << i << ' ' << m << nl;
    }

    cout << res;

    return 0;
}