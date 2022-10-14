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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[100500], b[100500], dp[100500][5];
set<string> f;
string s;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> a[0] >> a[1] >> a[2];
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i <= n; i++)
        for (j = 0; j <= 3; j++)
            dp[i][j] = -6LL*MOD*MOD;
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j <= 3; j++)
        {
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[j]*b[i]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    cout << dp[n][3] << endl;
    return 0;
}