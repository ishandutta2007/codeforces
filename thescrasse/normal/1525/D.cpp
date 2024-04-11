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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll dp[maxn][maxn], sf[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; k = 1;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            b[k] = i; k++;
        }
    }
    k--;

    for (i = 1; i <= k; i++) {
        sf[i][0] = INF;
        for (j = 1; j <= n; j++) {
            if (a[j] == 1) dp[i][j] = INF;
            else dp[i][j] = abs(b[i] - j) + sf[i - 1][j - 1];
            sf[i][j] = min(sf[i][j - 1], dp[i][j]);
        }
    }

    /* for (i = 1; i <= k; i++) {
        for (j = 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    cout << sf[k][n] << nl;

    return 0;
}