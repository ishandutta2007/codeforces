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
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
vector<pii> f, f1;
int dp[100500], a[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        dp[i] = MOD;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        if (a[i]) {
            int ans = MOD;
            for (int j = max(0, i-k+1); j <= i; j++)
                ans = min(ans, dp[j]);

            //cout << i << " " << ans << endl;
            for (int j = i; j <= i+k; j++)
                dp[j] = min(dp[j], ans+1);
        }
    if (dp[n] == MOD)
        cout << -1 << endl;
    else
        cout << dp[n] << endl;
    return 0;
}