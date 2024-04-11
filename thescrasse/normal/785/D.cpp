// 785D
// Anton and School - 2

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][2], fc[maxn], nv[maxn];
string s;

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        r = fxp(b, e / 2); return (r * r) % mod;
    } else {
        r = fxp(b, e - 1); return (b * r) % mod;
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

    cin >> s; n = s.size();

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i <= n; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    dp[0][0] = (s[0] == '(');
    dp[n - 1][1] = (s[n - 1] == ')');
    for (i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + (s[i] == '(');
    for (i = n - 1; i >= 0; i--) dp[i][1] = dp[i + 1][1] + (s[i] == ')');

    res = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            res += bnm(dp[i][0] + dp[i][1] - 1, dp[i][0]);
            res %= mod;
        }
    }

    cout << res;

    return 0;
}