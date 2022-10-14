#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz,ans;
ll dp[1005][2005][6], c[1050], b[1500];
void add(ll &x, ll y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    dp[0][1][0] = dp[0][1][3] = 1;
    dp[0][2][1] = dp[0][2][2] = 1;
    n--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < 4; l++)
            for (int r = 0; r < 4; r++) {
                int is = 0;
                if (l > 0 && r > 0 && l + r == 3)
                    is = 2;
                else if ((r == 3 && l != 0) || (r == 0 && l != 3) || l == r)
                    is = 0;
                else
                    is = 1;
                add(dp[i+1][j+is][r], dp[i][j][l]);
            }
        }
    //for (int i = 0; i < n; i++)
    //    for (int j = 0; j < k; j++)
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3])%MOD << endl;
    return 0;
}