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
ll a[100500];
ll Abs(ll x) {
    return x>0?x:-x;
}
vector<ll> g[100500];
ll potentials[100500];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= m; i++) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        ll sum = 0;
        int sz = g[i].size();
        for (int j = 0; j < g[i].size(); j++) {
            sum += g[i][j];
        }
        if (sum >= 0)
            potentials[g[i].size()] += sum;


        for (int j = sz-1; j >= 0; j--) {
            sum -= g[i][j];
            if (sum >= 0)
                potentials[j] += sum;
        }
    }

    ll t = 0, ans = 0;
    for (int i = n; i >= 0; i--) {
        t = potentials[i];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}