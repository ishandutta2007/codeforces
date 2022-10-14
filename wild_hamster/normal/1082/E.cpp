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
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
ll a[500500], b[500050], pa[500500];
vector<ll> g[500500];
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pa[i+1] = pa[i];
        if (a[i] == x)
            pa[i+1]++, k++;
        else
            g[a[i]].push_back(i);
    }
    ll ans = min(n, k + 1);
    for (int i = 1; i <= 500000; i++) {
        if (i == x || g[i].empty())
            continue;
        ll cur = 0, max_sum = 1, pos = g[i][0];
        for (int j = 1; j < g[i].size(); j++) {
            max_sum += 1 - (pa[g[i][j]+1] - pa[g[i][j-1]]);
            if (max_sum < 1)
                max_sum = 1;
            ans = max(ans, max_sum + k);
        }
    }
    cout << ans << endl;
    return 0;
}