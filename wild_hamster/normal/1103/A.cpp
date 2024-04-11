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
int ans1[4][2] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}};
int ans2[2][2] = {{1, 4}, {3, 4}};
int main() {
    std::string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cout << ans1[c2][0] << " " << ans1[c2][1] << endl;
            c2 = (c2 + 1) % 4;
        } else {
            cout << ans2[c1][0] << " " << ans2[c1][1] << endl;
            c1 = (c1 + 1) % 2;
        }
    }
    return 0;
}