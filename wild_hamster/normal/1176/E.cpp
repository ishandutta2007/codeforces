#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[500500], c[100500];
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}
ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll mulg(ll x, ll y) {
    return x * y % MOD;
}

void add(ll& x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}
vector<ll> g[300500], gr[300500];
ll used[300500];
vector<ll> ans[2];
void dfs_build_tree(ll v) {
    for (auto to : g[v]) {
        if (!used[to]) {
            gr[v].push_back(to);
            gr[to].push_back(v);
            used[to] = 1;
            dfs_build_tree(to);
        }
    }
}


void dfs(ll v, ll lv, ll p = -1) {
    ans[lv%2].push_back(v);
    for (auto to : gr[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, lv + 1, v);
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        gr[i].clear();
        used[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used[1] = 1;
    dfs_build_tree(1);

    ans[0].clear();
    ans[1].clear();
    ll c = 1;
    dfs(1, 0);

    if (ans[0].size() < ans[1].size()) {
        c = 0;
    }
    cout << ans[c].size() << endl;
    for (auto v : ans[c]) {
        printf("%d ", v);
    }
    printf("\n");
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}