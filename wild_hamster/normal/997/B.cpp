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
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
ll dp[5005][5005], b[5005];
ll a[4] = {1, 5, 10, 50};
int main() {

    //freopen("input.txt","r",stdin);
    n = 100;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 50*i; j++)
            for (int k = 0; k < 4; k++)
                dp[i+1][j+a[k]] |= dp[i][j];
    }
    for (int i = 0; i < 100; i++) {
        ll sum = 0;
        for (int j = 0; j <= 5000; j++)
            sum += dp[i][j];
        b[i] = sum;
    }
    cin >> n;
    if (n <= 20)
        cout << b[n] << endl;
    else
        cout << b[20] + 49LL*(n-20) << endl;
    return 0;
}