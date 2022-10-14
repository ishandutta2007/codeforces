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
vector<pii> g[300500];
void dfs(int v, int p = -1) {
    long long max1 = -(ll)1e+18, max2 = -(ll)1e+18;
    for (auto x : g[v]) {
        if (x.X == p)
            continue;
        ll val = x.Y;
        int to = x.X;
        dfs(to, v);
        dp[v] = max(dp[v], dp[to] + a[v] - val);
        if (dp[to] - val > max1) {
            max2 = max1;
            max1 = dp[to] - val;
        } else if (dp[to] - val > max2) {
            max2 = dp[to] - val;
        }
    }
    //cout << max1 << " " << max2 << " " << v << endl;
    dp[v] = max(dp[v], a[v]);
    ans = max(ans, dp[v]);
    ans = max(ans, max1 + max2 + a[v]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    for (int i = 0; i < n-1; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }
    ans = 0;
    dfs(1);
    cout << ans  << endl;
    return 0;
}