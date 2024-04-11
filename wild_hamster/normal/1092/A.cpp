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
ll  b[500050], pa[500500], dp[500500], ans;
ll Abs(ll x) {
    return x>0?x:-x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cout << char('a' + i%k);
        cout << endl;
    }
    return 0;
}