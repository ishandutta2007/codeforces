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
#define COL 10
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot;
int main() {
    //freopen("input.txt","r",stdin);
    ll v1,v2,t,d;
    cin >> v1 >> v2 >> t >> d;
    ll ans = 0;
    for (int i = 0; i < t; i++) {
        ans += min(v1+i*d, v2+(t-1-i)*d);
    }
    cout << ans << endl;
    return 0;
}