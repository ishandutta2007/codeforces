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
ll a[500500], b[500050], pa[500500], dp[500500], ans;
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2 == 0)
        return tmp;
    return x * tmp % MOD;
}

ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    cin >> n >> k;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ll sum = 0;
        for (int j = i ; j < n; j += k) {
            sum += a[j];
        }
        ans = max(ans, Abs(r - sum));
    }
    cout << ans << endl;
    return 0;
}