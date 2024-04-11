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
    ll x = 1LL*1500*1000*1000;
    ll n,H;
    cin >> n >> H;
    if (H >= x || H*(H+1)/2 >= n) {
        ll l = 1, r = x;
        while (l < r) {
            ll mid = (l+r)/2;
            if (mid*(mid+1)/2 >= n)
                r = mid;
            else
                l = mid+1;
        }
        cout << l << endl;
    } else {
        ll l = 1, r = x;
        while (l < r) {
            ll mid = (l+r)/2;
            if (mid*(mid+1)/2 + (H+mid-1)*(mid-1-H+1)/2 >= n)
                r = mid;
            else
                l = mid+1;
        }
        ll ans = 2*l-H;

        l = 1, r = x;
        while (l < r) {
            ll mid = (l+r)/2;
            if (mid*(mid+1)/2 + (H+mid)*(mid-H+1)/2 >= n)
                r = mid;
            else
                l = mid+1;
        }
        ans = min(ans, 2*l-H+1);
        cout << ans << endl;
    }
    return 0;
}