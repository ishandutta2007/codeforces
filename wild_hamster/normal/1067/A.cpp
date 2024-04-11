#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
vector<int> f, g;
int p[100500], a[100500], dp[100500][202][2];
void norm(int &x) {
    if (x >= MOD)
        x -= MOD;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] != -1)
        dp[0][a[0]][1] = 1;
    else {
        for (int i = 1; i <= 200; i++)
            dp[0][i][1] = 1;
    }
    for (int i = 1; i < n; i++) {
        int dp0 = 0, dp1 = 0;
        int l = 1, r = 200;
        if (a[i] != -1)
            l = r = a[i];
        for (int j = 1; j <= 200; j++) {
            if (j >= l && j <= r) {
                dp[i][j][1] += dp1;
                norm(dp[i][j][1]);
                dp[i][j][1] += dp0;
                norm(dp[i][j][1]);
            }
            dp1 += dp[i-1][j][1];
            dp0 += dp[i-1][j][0];
            norm(dp1);
            norm(dp0);
        }
        dp0 = 0, dp1 = 0;
        for (int j = 200; j >= 1; j--) {
            dp1 += dp[i-1][j][1];
            dp0 += dp[i-1][j][0];
            norm(dp1);
            norm(dp0);

            if (j >= l && j <= r) {
                dp[i][j][0] += dp[i-1][j][1];
                norm(dp[i][j][0]);
                dp[i][j][0] += dp0;
                norm(dp[i][j][0]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 200; i++)  {
        ans += dp[n-1][i][0];
        norm(ans);
    }
    cout << ans << endl;
    return 0;
}