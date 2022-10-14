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
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,xx, yy,INF, sz, used[55];
ll b[200500], a[200500], c[200500];
vector<ll> g[100500], f[100500];
bool inters(ll a, ll b, ll c, ll d) {
    bool flag = (max(min(a,b), min(c,d)) <= min(max(a,b), max(c,d)) && (a > b && c < d || a < b && c > d));
    return (min(b,a) >= min(c,d) && max(b,a) <= max(c,d) || 
        min(b,a) <= min(c,d) && max(b,a) >= max(c,d) || flag);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    if (n%4 != 0) {
        cout << "! -1" << endl;
        return 0;
    } else {
        ll l = 1, r = n/2+1;
        cout << "? " << l << endl;
        fflush(stdout);
        cin >> x;
        cout << "? " << r << endl;
        fflush(stdout);
        cin >> y;
        if (x == y) {
            cout << "! " << l << endl;
            return 0;
        }
        ll xl = l, xr = r, xvall = x, xvalr = y;
        ll yl = r, yr = l, yvall = y, yvalr = x;

        while (1) {
            ll mid1 = (xl + xr) / 2;
            ll mid2 = ((xl + xr) / 2 + n / 2 - 1) % n + 1;
            cout << "? " << mid1 << endl;
            fflush(stdout);
            cin >> x;
            cout << "? " << mid2 << endl;
            fflush(stdout);
            cin >> y;
            if (x == y) {
                cout << "! " << mid1 << endl;
                return 0;
            }
            if (xl+1 == xr) {
                cout << "! " << xl+1 << endl;
                return 0;
            }
            if (inters(xvall, x, yvall, y)) {
                xvalr = x;
                yvalr = y;
                xr = mid1;
                yr = mid2;
            } else {
                xvall = x;
                yvall = y;
                xl = mid1;
                yl = mid2;
            }
        }
    }
    return 0;
}