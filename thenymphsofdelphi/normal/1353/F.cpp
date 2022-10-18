#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e2 + 5, infll = 1e18 + 7;

int n, m;
int a[N][N], dp[N][N];

signed main(){
    int t; cin >> t;
    while (t--){
        int ans = infll;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for (int ii = 1; ii <= n; ii++){
            for (int jj = 1; jj <= m; jj++){
                int kek = a[ii][jj] - ii - jj + 2;
                if (kek > a[1][1]) continue;
                for (int i = 1; i <= n; i++){
                    dp[i][0] = infll;
                }
                for (int j = 1; j <= m; j++){
                    dp[0][j] = infll;
                }
                for (int i = 1; i <= n; i++){
                    for (int j = 1; j <= m; j++){
                        if (i == 1 && j == 1){
                            dp[i][j] = a[1][1] - kek;
                            continue;
                        }
                        if (a[i][j] < kek + i + j - 2){
                            dp[i][j] = infll;
                            continue;
                        }
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - kek - i - j + 2;
                    }
                }
                // if (kek != -6) continue;
                // for (int i = 0; i <= n; i++){
                //     for (int j = 0; j <= m; j++){
                //         cout << dp[i][j] << ' ';
                //     }
                //     cout << endl;
                // }
                // cout << kek << ' ' << dp[n][m] << endl;
                ans = min(ans, dp[n][m]);
            }
        }
        cout << ans << endl;
    }
}