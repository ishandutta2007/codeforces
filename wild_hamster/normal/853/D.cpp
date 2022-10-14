#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
vector<ll> t[800500];
ll a[300500], dp[300500][41];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] /= 1000;
    }
    for (i = 0; i <= n; i++)
        for (j = 0; j <= 40; j++)
            dp[i][j] = MOD;
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j <= 40; j++)
        {
            dp[i+1][max(j-a[i]*10,0)] = min(dp[i+1][max(j-a[i]*10,0)], dp[i][j] + a[i]*10 - min(j, a[i]*10));
            if (j+a[i] <= 40)
                dp[i+1][j+a[i]] = min(dp[i+1][j+a[i]], dp[i][j] + a[i]*10);
        }
    ll ans = MOD;
    for (i = 0; i <= 40; i++)
        ans = min(ans, dp[n][i]);
    cout << ans*100 << endl;
    return 0;
}