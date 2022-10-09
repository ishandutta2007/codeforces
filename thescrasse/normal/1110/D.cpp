// 1110D
// Jongmah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 1000010
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, f[maxn], dp[maxn][3][3], l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 1; i <= m; i++) f[m] = 0;
    for (i = 0; i < n; i++) {
        cin >> k; f[k]++;
    }

    for (i = 0; i <= m; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    for (i = 1; i <= m; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    if (j + k + l > f[i]) continue;
                    dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + l + (f[i] - j - k - l) / 3);
                }
            }
        }
    }

    cout << dp[m][0][0];

    return 0;
}