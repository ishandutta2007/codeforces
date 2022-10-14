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
ll Abs(ll x) {
    return x>0?x:-x;
}
char s[500500], t[500500];
int main() {
    cin >> n >> k;
    scanf("%s", s);
    scanf("%s", t);
    ll sum = 0, x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++) {
        x1 = x1 * 2 + s[i] - 'a';
        x2 = x2 * 2 + t[i] - 'a';
        x2 -= x1;
        x1 = 0;
        if (x2 >= k - 1) {
            sum += (n-i) * k;
            break;
        }
        sum += x2 + 1;
    }
    cout << sum << endl;
    return 0;
}