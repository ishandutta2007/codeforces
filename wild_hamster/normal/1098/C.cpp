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
ll  q, ans, w[100500], d[100500], p[100500];
set<ll> levels[100500], g[100500];
set<ll> leafs;
void dfs(ll v, ll p = -1) {
    w[v] = 1;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        dfs(to, v);
        w[v] += w[to];
    }
}

ll sum;


int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    if (m < 2*n - 1 || m > n*(n+1) / 2) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    ll l = 1, r = n-1;
    while (l < r) {

        ll mid = (l+r)/2;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            w[i] = 0;
        }
        ll cnt = 1;
        for (int i = 2; i <= n; i++) {
            if (g[cnt].size() == mid) {
                cnt++;
            }
            g[cnt].insert(i);
        }
        dfs(1);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += w[i];
        }
        if (sum <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }



    for (int i = 1; i <= n; i++) {
        g[i].clear();
        w[i] = 0;
    }
    ll cnt = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (g[cnt].size() == l) {
            cnt++;
        }
        g[cnt].insert(i);
        p[i] = cnt;
        d[i] = d[cnt] + 1;
    }
    dfs(1);
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += w[i];
    }

    ll max_level = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() < l) {
            levels[d[i]].insert(i);
            max_level = max(max_level, d[i]);
        }
        if (w[i] == 1) {
            leafs.insert(i);
        }
    }

    /*for (int i = 2; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;*/

    while (sum < m) {
        ll v = *(leafs.begin());
        leafs.erase(v);
        g[p[v]].erase(v);
        if (g[p[v]].size() == 0) {
            leafs.insert(p[v]);
        }
        levels[d[v]].erase(v);
        if (max_level - d[v] + 1 >= m - sum) {
            ll needed_level = m - sum + d[v] - 1;
            ll to = *(levels[needed_level].begin());
            p[v] = to;
            break;
        }
        ll to = *(levels[max_level].begin());
        //cout << v << " " << to << endl;
        p[v] = to;
        if (leafs.find(to) != leafs.end()) {
            leafs.erase(to);
        }
        sum += max_level - d[v] + 1;
        g[to].insert(v);
        if (g[to].size() == l) {
            levels[max_level].erase(to);
        }
        max_level++;
        levels[max_level].insert(v);
    }

    for (int i = 2; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}