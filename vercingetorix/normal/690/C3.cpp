#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

const int MAXL = 20;

vvi g;
int n;
vi par;
vvi p;
vi tin, tout;
vi depth;

int T = 0;

void dfs(int v, int pr) {
    p[0][v] = pr;
    for (int i = 1; i < MAXL; i++) {
        if (p[i - 1][v] != -1) {
            p[i][v] = p[i - 1][p[i - 1][v]];
        }
    }
    tin[v] = T++;
    
    for (int u : g[v]) {
        if (u == pr) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
    
    tout[v] = T++;
}

bool isAnc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
    if (isAnc(x, y)) return x;
    if (isAnc(y, x)) return y;
    for (int i = MAXL - 1; i >= 0; i--) {
        if (p[i][x] != -1 && !isAnc(p[i][x], y)) {
            x = p[i][x];
        }
    }
    return p[0][x];
}

int dist(int x, int y) {
    int z = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[z];
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    g = vvi(n);
    par = vi(n);
    p = vvi(MAXL, vi(n, -1));
    tin = tout = depth = vi(n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &par[i]);
        par[i]--;
        g[par[i]].pb(i);
    }
    dfs(0, -1);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        int dx = dist(x, i);
        int dy = dist(y, i);
        if (max(dx, dy) > dist(x, y)) {
            if (dx > dy) {
                y = i;
            } else {
                x = i;
            }
        }
        printf("%d\n", dist(x, y));
    }
    return 0;
}