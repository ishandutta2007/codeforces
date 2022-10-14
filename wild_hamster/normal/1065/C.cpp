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
#define MOD 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;
ll a[500500], pa[500500];
int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        pa[i+1] = pa[i] + a[i];
    ll p = n-1;
    ll ans = 0, cur = a[p];
    if (cur == a[0]) {
        cout << 0 << endl;
        return 0;
    }
    while (p > 0) {
        ll sum = 0;
        for (ll i = 1; i <= 500000; i++) {
            ll pos = upper_bound(a, a+n, cur-i) - a;
            //cout << i << " " << pa[p+1] - pa[pos+1] - (cur-i)*(p-pos) + (n-p)*i << endl;
            if (pa[p] - pa[pos] - (cur-i)*(p-pos) + (n-p)*i > k || i == 500000) {
                cur -= i-1;
                p = upper_bound(a, a+n, cur-1) - a;
                break;
            }
        }
        ans++;
        //cout << p << " " << cur << endl;
    }
    cout << ans << endl;
    return 0;
}