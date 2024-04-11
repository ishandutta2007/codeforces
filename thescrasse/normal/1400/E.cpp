#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, mn, l, r, dp[maxn][2], pt[maxn][3];
int adj[maxn][maxn];
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i]; adj[0][i] = a[i];
    }

    m = 1;
    while (true) {
        mn = INF; v.clear();
        for (i = n - 1; i >= 0; i--) {
            if (v.empty() && a[i] != 0) v.pb(i);
            else if (v.size() == 1 && a[i] == 0) v.pb(i + 1);
        }
        if (v.empty()) break;
        if (v.size() == 1) v.pb(0);
        l = v[1]; r = v[0];
        for (i = l; i <= r; i++) mn = min(mn, a[i]);
        for (i = l; i <= r; i++) a[i] -= mn;

        pt[m][0] = l; pt[m][1] = r; pt[m][2] = mn;
        for (i = 0; i < n; i++) adj[m][i] = a[i];
        m++;
    }

    // for (i = 1; i < m; i++) cout << pt[i][0] << ' ' << pt[i][1] << ' ' << pt[i][2] << nl;

    for (j = 0; j < n; j++) {
        if (j == 0) {
            for (i = 0; i < m; i++) dp[i][0] = 0;
        } else {
            for (i = 0; i < m; i++) dp[i][0] = dp[i][1];
        }

        k = 0;
        for (i = m - 1; i >= 0; i--) {
            dp[i][1] = INF;
            dp[i][1] = min(dp[i][1], dp[i][0] + (adj[i][j] != 0));
            if (i < m - 1) {
                if (pt[i + 1][0] <= j) dp[i][1] = min(dp[i][1], dp[i + 1][1] + pt[i + 1][2]);
                else dp[i][1] = min(dp[i][1], dp[i + 1][1]);
            }
        }

        /* for (i = 0; i < m; i++) cout << dp[i][1] << ' ';
        cout << nl; */
    }

    cout << dp[0][1];

    return 0;
}