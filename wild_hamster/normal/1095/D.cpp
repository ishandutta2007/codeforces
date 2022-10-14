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
ll n,m,k, y, z, l, i, j, p, x;
ll  a[500050][2], b[505000], pa[500500], dp[500500], ans;
ll Abs(ll x) {
    return x>0?x:-x;
}
string s[305];

int main() {
    cin >> n;
    if (n == 3) {
        cout << "1 2 3\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
        if (a[a[i][0]][0] == a[i][1] || a[a[i][0]][1] == a[i][1]) {
            b[i] = a[i][0];
        } else {
            b[i] = a[i][1];
        }
    }
    x = 1;
    for (int i = 1; i <= n; i++) {
        cout << (x = b[x]) << " ";
    }
    return 0;
}