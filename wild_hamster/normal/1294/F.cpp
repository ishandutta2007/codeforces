#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[400500];
vector<ll> g[100500];

ll up[200500][25], tin[200500], tout[200500], w[200050], ww[200050];
ll timer;

bool upper(ll v, ll u) {
    return tin[u] >= tin[v] && tout[u] <= tout[v];
}

void dfs2(ll v, ll lvl, ll p = 1) {
    w[v] = lvl;
    ww[lvl] = v;

    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs2(to, lvl+1, v);
    }
}

void dfs(ll v, ll lvl, ll p) {
    tin[v] = ++timer;
    w[v] = lvl;
    ww[lvl] = v;

    up[v][0] = p;
    for (int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, lvl+1, v);
    }
    tout[v] = timer;
}

ll lca(ll x, ll y) {
    ll ans = 0;
    if (upper(x, y)) {
        return x;
    }
    if (upper(y, x)) {
        return y;
    }
    for (int i = 19; i >= 0; i--) {
        if (upper(up[x][i], y)) {
            continue;
        }
        x = up[x][i];
    }
    return up[x][0];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n-1; i++) {
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs2(1, 0);
    ll u = 0;
    for (int i = n; i >= 0; i--) {
        if (ww[i] != 0) {
            u = ww[i];
            break;
        }
    }
    dfs(u, 0, u);
    ll v = 0;
    ll cr = 0;
    for (int i = n; i >= 0; i--) {
        if (ww[i] != 0) {
            v = ww[i];
            cr = i;
            break;
        }
    }

    vector<ll> hyu;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (u != i && v != i) {
            ll lcuv = lca(u, v);
            ll lcui = lca(u, i);
            ll lciv = lca(i, v);
            ll dst = (w[u] + w[i] + w[v]) - w[lcuv] - w[lcui] - w[lciv];
            if (dst > ans) {
                ans = dst;
                hyu = {u, v, i};
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < 3; i++) {
        cout << hyu[i] << " ";
    }


    return 0;
}