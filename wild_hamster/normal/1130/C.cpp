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
ll a[55][55], b[500050], pa[500500], dp[500500], ans, BB, pp;
vector<pii> f[2];
ll dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
void dfs(ll x, ll y, ll p) {
    f[p].push_back(mp(x,y));
    a[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        ll dx = x + dirs[i][0];
        ll dy = y + dirs[i][1];
        if (a[dx][dy]) {
            dfs(dx, dy, p);
        }
    }
}
int main() {
    cin >> n;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            char c;
            cin >> c;
            a[i + 1][y + 1] = 1 - c + '0';
        }
    }
    dfs(x1, y1, 0);
    dfs(x2, y2, 1);
    ll ans =345093056;
    auto hyu = [] (ll x) {return x*x;};
    for (auto x : f[0]) {
        for (auto y : f[1]) {
            ans = min(ans, hyu(x.X-y.X) + hyu(x.Y-y.Y));
        }
    }
    cout << ans << endl;
    return 0;
}