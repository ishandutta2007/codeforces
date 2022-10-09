// 675E
// Trains and Statistic

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn];
array<ll, 2> sg[262154], x;

array<ll, 2> rmq(ll a, ll b) {
    array<ll, 2> r = {-INF, -INF};
    a += m; b += m;
    while (a <= b) {
        if (a % 2 == 1) {
            r = max(r, sg[a]); a++;
        }
        if (b % 2 == 0) {
            r = max(r, sg[b]); b--;
        }
        a /= 2; b /= 2;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i < n; i++) {
        cin >> a[i];
    }
    a[n] = n;

    m = 131072; sg[m] = {-INF, -INF};
    for (i = m + 1; i <= m + n; i++) {
        if (i <= m + n) sg[i] = {a[i - m], i - m};
        else sg[i] = {-INF, -INF};
    }

    for (i = m - 1; i >= 1; i--) {
        sg[i] = max(sg[2 * i], sg[2 * i + 1]);
    }

    dp[n] = 0;
    for (i = n - 1; i >= 1; i--) {
        x = rmq(i + 1, a[i]);
        // cout << i + 1 << ' ' << a[i] << ' ' << x[0] << ' ' << x[1] << nl;
        dp[i] = dp[x[1]] + (n - a[i]) + (x[1] - i);
    }

    res = 0;
    for (i = 1; i <= n; i++) res += dp[i];

    cout << res;

    return 0;
}