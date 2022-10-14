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
ll n,i,j,k,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[300500], b[300500], pa[300500], pb[300500], pa1[300500], pb1[300500], pa2[300500], pb2[300500];

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &b[i]);
    }

    pa1[n-1] = pa2[n-1] = a[n-1];
    ll sum = a[n-1];
    pa[n-1] = sum;
    for (int i = n-2; i >= 0; i--) {
        pa1[i] = pa1[i+1] + (n-i)*a[i];
        sum += a[i];
        pa[i] = sum;
        pa2[i] = pa2[i+1]+sum;
    }

    pb1[n-1] = pb2[n-1] = b[n-1];
    sum = b[n-1];
    pb[n-1] = sum;
    for (int i = n-2; i >= 0; i--) {
        pb1[i] = pb1[i+1] + (n-i)*b[i];
        sum += b[i];
        pb[i] = sum;
        pb2[i] = pb2[i+1]+sum;
    }

    ll ans = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        ll l = n-i;
        if (i%2 == 0) {
            ans = max(ans, sum + 2*i*pa[i] + 2*i*pb[i] + pa2[i] + l*pb[i] + pb1[i]);
            sum += a[i]*(i*2+1) + b[i]*(i*2+2);
        } else {
            ans = max(ans, sum + 2*i*pa[i] + 2*i*pb[i] + pb2[i] + l*pa[i] + pa1[i]);
            sum += b[i]*(i*2+1) + a[i]*(i*2+2);
        }
    }
    for (int i = 0; i < n; i++)
        ans -= a[i] + b[i];
    cout << ans << endl;
    return 0;
}