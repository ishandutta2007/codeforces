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
ll n, m,k, y, z, l, i, j, x, r;
ll a[500005], b[500050], p[500500], dp[500500], BB, pp, used[500500];
vector<ll> f;
vector<pii> ans;
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        b[i+1] = b[i] + a[i];
    }
    for (int i = 1; i <= k; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x <= k) {
            p[x] = min(p[x], x - y);
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = (ll)1e+18;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i+j] = min(dp[i+j], dp[i] + b[i+j] - b[i+j-p[j]]);
        }
    }
    cout << dp[k] << endl;
    return 0;

}