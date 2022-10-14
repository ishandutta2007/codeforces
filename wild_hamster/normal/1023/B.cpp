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
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,xx, yy,INF, sz, sum;
ll a[105], dp[505], fac[100500], invfac[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    if (n >= k-1) {
        cout << (k-1)/2 << endl;
        return 0;
    }
    if (n + n - 1 < k) {
        cout << 0 << endl;
        return 0;
    }
    m = k-n;
    cout << (k-1)/2-m+1 << endl;
    return 0;
}