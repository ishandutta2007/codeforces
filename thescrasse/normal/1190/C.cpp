// 1190C
// Tokitsukaze and Duel

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p[2][2], d[2], dp[maxn];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> s; m = 0;
    p[0][0] = INF; p[1][0] = INF; p[0][1] = -INF; p[1][1] = -INF;
    for (i = 0; i < n; i++) {
        j = (ll)s[i] - 48;
        p[j][0] = min(p[j][0], i); p[j][1] = max(p[j][1], i);
        if (i == 0) dp[i] = 1;
        else if (s[i] != s[i - 1]) dp[i] = 1;
        else dp[i] = dp[i - 1] + 1;
        m = max(m, dp[i]);
    }

    d[0] = p[0][1] - p[0][0] + 1; d[1] = p[1][1] - p[1][0] + 1;
    // cout << d[0] << ' ' << d[1] << ' ' << m << nl;

    if (d[0] <= k || d[1] <= k) {
        cout << "tokitsukaze"; return 0;
    }

    if (m >= k) {
        cout << "once again"; return 0;
    }

    if (d[0] <= k + 1 && d[1] <= k + 1) {
        cout << "quailty"; return 0;
    }

    cout << "once again";

    return 0;
}