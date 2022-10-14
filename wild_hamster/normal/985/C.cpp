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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[100500];
ll b[2005];
set<ll> f;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k >> l;
    for (int i = 0; i < n*k; i++) {
        cin >> a[i];
    }
    sort(a, a+n*k);
    ll r = a[0]+l;
    ll l = a[0];
    for (int i = 0; i < n*k; i++) {
        if (a[i] <= r && i%k != 0)
            f.insert(a[i]);
    }
    for (int i = 0; i < n*k; i++)
    if (i % k == 0) {
        if (a[i] <= r)
            ans += a[i];
        else
            z++;
    }
    if (f.size() < z) {
        cout << 0 << endl;
        return 0;
    }
    auto itr = f.end();
    while (z-->0) {
        itr--;
        ans += *itr;
    }
    cout << ans << endl;
    return 0;
}