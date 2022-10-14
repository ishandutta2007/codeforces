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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[100500];
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n/2; i++)
        cin >> a[i];
    sort(a, a+n/2);
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n/2; i++) {
        ans1 += Abs(1+i*2-a[i]);
        ans2 += Abs(2+i*2-a[i]);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}