
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef int ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
vector<ll> g[100500], pshe;
ll lvx[100500], lvy[100500], px[100500], py[100500], dx[100500], dy[100500], d[100500], O, flag;
void dfsx(ll v, ll lv = 0, ll p = -1) {
    px[v] = p;
    lvx[v] = lv;
    dx[v] = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfsx(to, lv + 1, v);
        dx[v] = max(dx[v], dx[to] + 1);
    }
}

void dfsy(ll v, ll lv = 0, ll p = -1) {
    py[v] = p;
    lvy[v] = lv;
    dy[v] = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfsy(to, lv + 1, v);
        dy[v] = max(dy[v], dy[to] + 1);
    }
}


void dfs_mag(ll v, ll p = -1) {
    d[v] = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs_mag(to, v);
        d[v] = max(d[v], d[to] + 1);
    }
}

void dfs(ll v, ll mx = 0, ll p = -1) {
    ll mx1 = -1, mx2 = -1, mx3 = -1;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        if (d[to] > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = d[to];
        } else if (d[to] > mx2) {
            mx3 = mx2;
            mx2 = d[to];
        } else if (d[to] > mx3) {
            mx3 = d[to];
        }
    }
    if (mx3 >= O - 1 || (mx2 >= O - 1 && mx >= O)) {
        flag = 1;
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        if (d[to] == mx1) {
            dfs(to, max(mx + 1, mx2 + 2), v);
        } else {
            dfs(to, max(mx + 1, mx1 + 2), v);
        }
    }
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 0 ;i < n-1; i++) {
        ll z1, z2;
        cin >> z1 >> z2;
        g[z1].push_back(z2);
        g[z2].push_back(z1);
    }
    dfsx(x);
    dfsy(y);
    ll sz = lvx[y] - lvx[x];
    O = sz;
    ll cur = sz;
    while (1) {
        if (dx[y] + dy[x] <= (cur - sz) * 2) {
            cout << "NO\n";
            return;
        } else {
            if (dx[y] > dy[x]) {
                x = py[x];
            } else {
                y = px[y];
            }
            sz--;
        }
        if (x == y) {
            break;
        }
    }
    flag = 0;
    dfs_mag(1);
    dfs(1);
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}