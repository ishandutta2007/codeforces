#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, ans;
ll a[200500],  b[200500];
ll dp[5005][5005], sum[5005][5005], p[5005];
ll fi(ll l, ll r) {
    if ((r-l)%2 == 0)
        return (a[l]^a[r]);
    return (p[l]^p[r+1]);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        p[i+1] = (p[i]^a[i]);
    }
    for (int i = 0; i < n; i++)
        dp[i][0] = a[i], sum[i][0] = a[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j+i < n; j++) {
            sum[j][i] = (sum[j][i-1] ^ sum[j+1][i-1]);
            dp[j][i] = max(sum[j][i], max(dp[j][i-1], dp[j+1][i-1]));
        }
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x, y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        printf("%d\n", dp[x][y-x]);
    }
    return 0;
}