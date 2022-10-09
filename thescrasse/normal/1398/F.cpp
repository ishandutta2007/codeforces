// 1398F
// Controversial Rounds

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, r[maxn], dp[maxn][2], x, l, sz;
string s;
vector<ll> p[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s;

    dp[n][0] = 0; dp[n][1] = 0;
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == '0') dp[i][0] = 0;
        else dp[i][0] = dp[i + 1][0] + 1;
        if (s[i] == '1') dp[i][1] = 0;
        else dp[i][1] = dp[i + 1][1] + 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (i == 0 || dp[i - 1][j] == 0) {
                for (k = 1; k <= dp[i][j]; k++) p[k].pb(i);
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (auto u : p[i]) cout << u << ' ';
        cout << nl;
    } */

    for (i = 1; i <= n; i++) {
        // cout << i << ' ' << sz << nf;
        res = 0; j = 0; l = 0; sz = p[i].size();
        while (true) {
            // cout << j << ' ' << l << nf;
            if (j >= n || l >= sz) break;
            if ((s[j] != '0' && dp[j][0] >= i) || (s[j] != '1' && dp[j][1] >= i)) {
                res++; j += i;
            } else {
                while (l < sz && p[i][l] < j) l++;
                if (l == sz) break;
                j = p[i][l];
            }
        }

        cout << res << ' ';
    }

    return 0;
}