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

const int N = 2e3 + 5;

int n, k;
char a[N][N];
int dp[N][N];
bool reach[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j];
        }
    }
    reach[0][1] = 1;
    int farthestA = 1;
    ForE(i, 1, n){
        ForE(j, 1, n){
            dp[i][j] = 2 * N;
            if (i == 1 && j == 1){
                dp[i][j] = 0;
            }
            if (i > 1){
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (j > 1){
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
            if (a[i][j] != 'a'){
                dp[i][j]++;
            }
            if (dp[i][j] <= k){
                farthestA = max(farthestA, i + j);
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (i + j == farthestA && dp[i][j] <= k){
                reach[i][j] = 1;
            }
        }
    }
    ForE(i, 2, farthestA){
        cout << 'a';
    }
    ForE(dia, farthestA + 1, 2 * n){
        char minChar = 'z' + 1;
        ForE(i, 1, n){
            int j = dia - i;
            if (j < 1 || j > n){
                continue;
            }
            if (reach[i - 1][j] || reach[i][j - 1]){
                minChar = min(minChar, a[i][j]);
            }
        }
        cout << minChar;
        ForE(i, 1, n){
            int j = dia - i;
            if (j < 1 || j > n){
                continue;
            }
            if ((reach[i - 1][j] || reach[i][j - 1]) && a[i][j] == minChar){
                reach[i][j] = 1;
            }
        }
    }
}