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
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz;
ll a[100500], dp[100500][15];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int k = 0; k < 8; k++)
            dp[i][k] = MOD;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        int mask = 0;
        cin >> x >> s;
        for (int j = 0; j < s.size(); j++)
            mask |= (1 << (s[j] - 'A'));
        for (int k = 0; k < 8; k++) {
            dp[i+1][k|mask] = min(dp[i+1][k|mask], dp[i][k] + x);
            dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
        }
    }
    if (dp[n][7] == MOD)
        cout << -1 << endl;
    else
        cout << dp[n][7] << endl;
    return 0;
}