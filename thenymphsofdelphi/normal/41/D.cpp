#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

const int N = 1e2 + 5, K = 1e1 + 5;

int n, m, k;
int a[N][N];
int dp[N][N][K];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k; k++;
    ForE(i, 1, n){
        ForE(j, 1, m){
            char c; cin >> c; a[i][j] = c - '0';
        }
    }
    ForE(x, 0, n + 1){
        ForE(y, 0, m + 1){
            For(z, 0, k){
                dp[x][y][z] = -1e9;
            }
        }
    }
    ForE(y, 0, m + 1){
        dp[n + 1][y][0] = 0;
    }
    FordE(x, n, 1){
        ForE(y, 1, m){
            For(z, 0, k){
                dp[x][y][z] = max(dp[x + 1][y - 1][(z + 10 * k - a[x][y]) % k],
                                  dp[x + 1][y + 1][(z + 10 * k - a[x][y]) % k]) + a[x][y];
            }
        }
    }
    int ans = -1;
    ForE(y, 1, m){
        ans = max(ans, dp[1][y][0]);
    }
    if (ans == -1){
        cout << ans << endl;
        return 0;
    }
    int ty = 0, tz = 0;
    ForE(y, 1, m){
        if (dp[1][y][0] == ans){
            ty = y;
            break;
        }
    }
    string sans;
    For(x, 1, n){
        if (dp[x + 1][ty - 1][(tz + 10 * k - a[x][ty]) % k] >
            dp[x + 1][ty + 1][(tz + 10 * k - a[x][ty]) % k]){
            tz = (tz + 10 * k - a[x][ty]) % k;
            ty--;
            sans += 'R';
        }
        else{
            tz = (tz + 10 * k - a[x][ty]) % k;
            ty++;
            sans += 'L';
        }
    }
    reverse(bend(sans));
    cout << ans << endl << ty << endl << sans << endl;
}