#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
ll dp[maxn][2], pm[maxn][2];
string s, t;
vector<ll> adj[30][2];

void reset() {
    ll i, j;
    flag[0] = 0;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 1; j++) {
            dp[i][j] = 0; pm[i][j] = 0;
        }
    }
    for (i = 1; i <= 26; i++) {
        for (j = 0; j <= 1; j++) {
            adj[i][j].clear();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        cin >> s >> t;
        n = s.size(); m = t.size(); s = '#' + s; t = '#' + t;
        reset();
        for (i = 1; i <= m; i++) {
            adj[(ll)t[i] - 'a' + 1][i % 2].pb(i);
        }

        for (i = 1; i <= n; i++) {
            for (j = 0; j <= 1; j++) {
                k = pm[i - 1][j ^ 1];
                auto it = upper_bound(adj[(ll)s[i] - 'a' + 1][j].begin(),
                    adj[(ll)s[i] - 'a' + 1][j].end(), k + 1);
                if (it == adj[(ll)s[i] - 'a' + 1][j].begin()) {
                    dp[i][j] = 0;
                } else {
                    it--; dp[i][j] = (*it);
                }
                if (i >= 3) pm[i][j] = max(pm[i - 2][j], dp[i][j]);
                else pm[i][j] = dp[i][j];

                if ((i + n) % 2 == 0 && dp[i][j] == m) flag[0] = 1;
            }
        }

        /*  for (i = 1; i <= n; i++) {
            for (j = 0; j <= 1; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << nl;
        } */

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}