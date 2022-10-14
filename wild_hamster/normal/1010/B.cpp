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
#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll b[200500], a[200500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output3.txt", "w", stdout);
    //cin >> n >> m;
    //n = 1000, m = 1000;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cout << 1 << endl;
        fflush(stdout);
        cin >> x;
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }
    i = 0;
    ll l = 1, r = m;
    while (1) {
        ll mid = (l+r)/2;
        cout << mid << endl;
        fflush(stdout);
        cin >> x;
        if (x == 0) {
            return 0;
        }
        x *= a[i%n];
        i++;
        if (x > 0)
            l = mid+1;
        else
            r = mid-1;
    }
    return 0;
}