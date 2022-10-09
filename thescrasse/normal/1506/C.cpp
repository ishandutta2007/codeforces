#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], dp[maxn][maxn];
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a >> b; n = a.size(); m = b.size(); a = '#' + a; b = '#' + b;
        res = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (a[i] != b[j]) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }

        cout << n + m - 2 * res << nl;
    }

    return 0;
}