#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int Mod = 998244353;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}

const int MAXN = 2005;


int n, a[MAXN][MAXN], dist[MAXN][MAXN];
int par[MAXN];
vector<pair<int, int>> g[MAXN];

int root(int u) {
    return u == par[u] ? u : par[u] = root(par[u]);
}

void unite(int u, int v) {
    u = root(u), v = root(v);
    par[u] = v;
}

void dfs(int u, int p, int depth, int i) {
    dist[i][u] = depth;
    for (auto v: g[u]) {
        if (v.first != p) {
            dfs(v.first, u, depth + v.second, i);
        }
    }
}

void solve() {
    cin >> n;
    iota(par, par + n, 0);
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0 && i != j) {
                cout << "NO\n";
                return;
            }
            pos.push_back({i, j});
        }
    }
    sort(all(pos), [&](pair<int, int> x, pair<int, int> y) {
        return a[x.first][x.second] < a[y.first][y.second];
    });
    for (auto p: pos) {
        if (root(p.first) != root(p.second)) {
            g[p.first].push_back({p.second, a[p.first][p.second]});
            g[p.second].push_back({p.first, a[p.first][p.second]});
            unite(p.first, p.second);
        }
    }
    for (int i = 0; i < n; i++) {
        dfs(i, -1, 0, i);
        for (int j = 0; j < n; j++) {
            if (a[i][j] != dist[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}