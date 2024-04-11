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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (j = 0; j < 1000000; j++)
            if (y*j+x > ans) {
                ans = y*j+x;
                break;
            }
    }
    cout << ans << endl;
    return 0;
}