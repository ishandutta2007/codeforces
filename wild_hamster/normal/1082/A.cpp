#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
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
ll n,m,k, y, z, l, i, j, p, x;
ll a[100500];
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        if (Abs(y - x) % d == 0) {
            cout << Abs(y-x)/d << endl;
            continue;
        }
        ll ans = (ll)1e+18;
        if ((n-y) % d == 0) {
            ans = min(ans, (n-x+d-1)/d + (n-y)/d);
        }
        if ((y-1) % d == 0) {
            ans = min(ans, (x-1+d-1)/d + (y-1)/d);
        }
        if (ans == (ll)1e+18) {
            ans = -1;
        }
        cout << ans << endl;
    }

    return 0;
}