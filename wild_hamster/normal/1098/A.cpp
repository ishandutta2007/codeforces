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
ll n,m,k, y, z, l, i, j, x;
ll  q, ans, a[100500], b[100500], c[100500];
vector<ll> g[100500];
void dfs(int v, int p = -1) {
    ll min1 = MOD;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        min1 = min(min1, b[to]);
        dfs(to, v);
    }
    if (b[v] == -1) {
        if (min1 != MOD)
            b[v] = min1;
        else
            b[v] = b[c[v]];
    }
}

void dfs_check(int v, int p = -1) {
    for (auto to : g[v]) {
        if (to == p)
            continue;
        c[to] = c[v] + a[to];
        dfs_check(to, v);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        c[i] = x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    a[1] = b[1];
    dfs(1);
    ll sum = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = b[i] - b[c[i]];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}