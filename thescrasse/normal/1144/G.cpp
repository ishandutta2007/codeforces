// 1144G
// Two Merged Sequences

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
array<ll, 2> dp[maxn][2];
vector<ll> r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = -INF; dp[0][1][0] = INF;
    dp[1][0][0] = -INF; dp[1][1][0] = INF;
    for (i = 2; i <= n; i++) {
        dp[i][0][0] = INF; dp[i][1][0] = -INF;
        if (a[i] < a[i - 1]) dp[i][0] = min(dp[i][0], {dp[i - 1][0][0], 0});
        if (a[i] > a[i - 1]) dp[i][1] = max(dp[i][1], {dp[i - 1][1][0], 1});
        if (a[i] < dp[i - 1][1][0]) dp[i][0] = min(dp[i][0], {a[i - 1], 1});
        if (a[i] > dp[i - 1][0][0]) dp[i][1] = max(dp[i][1], {a[i - 1], 0});
    }

    /* for (i = 1; i <= n; i++) {
        cout << dp[i][0][0] << ' ' << dp[i][1][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][1] << nl;
    } */

    if (dp[n][0][0] != INF) k = 0;
    else if (dp[n][1][0] != -INF) k = 1;
    else k = -1;

    if (k == -1) {
        cout << "NO"; return 0;
    }

    cout << "YES" << nl;
    r.pb(k);
    for (i = n; i >= 2; i--) {
        k = dp[i][k][1]; r.pb(k);
    }

    reverse(r.begin(), r.end());
    for (auto u : r) cout << (u ^ 1) << ' ';

    return 0;
}