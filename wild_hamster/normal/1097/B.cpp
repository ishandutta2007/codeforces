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
#define MOD ((1<<30)-1)
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  a[1500050], b[505000], p[500500], dp[500500], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1<<n); i++) {
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j)&1) {
                ans += a[j];
            } else {
                ans -= a[j];
            }
        }
        if (ans % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}