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
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y;
ll a[1200005], d[1205000];
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = (tmp*tmp)%MOD;
    if (y%2)
        return x*tmp%MOD;
    return tmp;
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> x >> k;
    ll ans = ((x%MOD*binpow(2,k)%MOD+((x+MOD-1)%MOD*binpow(2,k)%MOD+1)%MOD))%MOD;
    if (x == 0)
        ans = 0;
    cout << ans << endl;
    return 0;
}