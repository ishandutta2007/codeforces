// 1198D
// Rectangle Painting 1

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 51

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][maxn][maxn][maxn], l, r, c, ps[maxn][maxn], x;
char mt[maxn][maxn];

void upd(ll i, ll j, ll k, ll l) {
    r = k - i + 1; c = l - j + 1;
    if (r == 1 && c == 1) return;
    dp[i][j][k][l] = max(r, c);
    for (m = i; m < k; m++) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][m][l] + dp[m + 1][j][k][l]);
    for (m = j; m < l; m++) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][k][m] + dp[i][m + 1][k][l]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> mt[i][j];
            if (mt[i][j] == '#') dp[i][j][i][j] = 1;
            else dp[i][j][i][j] = 0;
        }
    }

    for (r = 1; r <= n; r++) {
        for (c = 1; c <= n; c++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (i + r - 1 > n || j + c - 1 > n) continue;
                    upd(i, j, i + r - 1, j + c - 1);
                }
            }
        }
    }

    cout << dp[1][1][n][n];

    return 0;
}