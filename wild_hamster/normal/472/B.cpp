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
#define COL 30000
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x;
ll a[2005];

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ll pos = n-1;
    ll ans = 0;
    while (pos >= 0) {
        ans += (a[pos]-1)*2;
        pos -= k;
    }
    cout << ans << endl;
    return 0;
}