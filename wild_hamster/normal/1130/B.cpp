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
#include <optional>
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
ll n, m,k, y, z, l, i, j, p, x, r;
ll a[500500], b[500050], pa[500500], dp[500500], ans, BB, pp;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
int main() {
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> x;
        if (a[x] == 0)
            a[x] = i+1;
        else
            b[x] = i+1;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++ ) {
        ans += Abs(b[i]-b[i+1]) + Abs(a[i] - a[i+1]);
    }
    ans += b[1] - 1 + a[1] - 1;
    cout << ans << endl;
    return 0;
}