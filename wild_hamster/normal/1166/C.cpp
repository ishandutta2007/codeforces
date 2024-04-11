#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>

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
#define MOD 1000003
typedef long long ll;
using namespace std;

ll a[300500], x, y, z, n, m, q;
ll b[500500];
string pat = "aoeui";
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            x = -x;
        }
        a[i] = x;
    }
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll y = upper_bound(a, a+n, a[i] * 2) - a;
        ans += y - i - 1;
    }
    cout << ans << endl;
    return 0;
}