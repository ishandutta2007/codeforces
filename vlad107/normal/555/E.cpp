#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define pb push_back
#define mp make_pair
#define y0 y00000000
#define y1 y11111111
#define next nextttt
#define prev prevvvv

using namespace std;

const int N = 4e5;
const int K = 20;

map<pair<int, int>, int> cnt;
pair<int, int> u[N];
int n, m, q, curt, mtin[N], tin[N], nom[N], blocked[N], cnom, used[N], tout[N];
vector< pair<int, int> > g[N];
vector<int> e[N];
int pr[N][K], need0[N], need1[N];

void bfs() {
    memset(nom, -1, sizeof(nom));
    cnom = 0;
    for (int i = 0; i < n; i++) {
        if (nom[i] < 0) {
            queue<int> q;
            q.push(i);
            nom[i] = cnom;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int j = 0; j < g[x].size(); j++) {
                    int y = g[x][j].first;
                    int id = g[x][j].second;
                    if ((!blocked[id]) && (nom[y] < 0)) {
                        nom[y] = cnom;
                        q.push(y);
                    }
                }
            }
            ++cnom;
        }
    }
}

void dfs(int x, int px) {
    tin[x] = mtin[x] = curt++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i].first;
        int id = g[x][i].second;
        if (y == px) continue;
        if (tin[y] < 0) {
            dfs(y, x);
            if ((mtin[y] > tin[x]) && (cnt[mp(x,y)] == 1)) {
                blocked[id] = 1;
            }
            mtin[x] = min(mtin[x], mtin[y]);
        } else {
            mtin[x] = min(mtin[x], tin[y]);
        }
    }
}

void dfs2(int x, int px) {
    pr[x][0] = px;
    for (int i = 1; i < K; i++) {
        if (pr[x][i - 1] == -1) {
            pr[x][i] = -1; 
        } else {
            pr[x][i] = pr[pr[x][i - 1]][i - 1];
        }
    }
    tin[x] = curt++;
    used[x] = 1;
    for (int i = 0; i < e[x].size(); i++) {
        int y = e[x][i];
        if (!used[y]) {
            dfs2(y, x);
        }
    }
    tout[x] = curt++;
}

void dfs3(int x, int px) {
    used[x] = 1;
    for (int i = 0; i < e[x].size(); i++) {
        int y = e[x][i];
        if (!used[y]) {
            dfs3(y, x);
            if ((need0[y] > 0) && (need1[y] > 0)) {
                puts("No");
                exit(0);
            }
            need0[x] += need0[y];
            need1[x] += need1[y];
        }
    }
}

bool par(int x, int y) {
    return ((tin[x] <= tin[y]) && (tout[y] <= tout[x]));
}

int lca(int x, int y) {
    if (par(x, y)) return x;
    if (par(y, x)) return y;
    for (int i = K - 1; i >= 0; i--) {
        int px = pr[x][i];
        if (px == -1) continue;
        if (!par(px, y)) x = px;
    }
    return pr[x][0];
}

int main() {
    // freopen("e.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        cnt[mp(x, y)]++;
        cnt[mp(y, x)]++;
        g[x].pb(mp(y,i));
        g[y].pb(mp(x,i));
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &u[i].first, &u[i].second);
        --u[i].first;
        --u[i].second;
    }
    bfs();
    for (int i = 0; i < q; i++) {
        if (nom[u[i].first] != nom[u[i].second]) {
            puts("No");
            return 0;
        }
    }
    memset(tin, -1, sizeof(tin));
    curt = 0;
    for (int i = 0; i < n; i++) {
        if (tin[i] < 0) dfs(i, -1);
    }
    bfs();
    for (int i = 0; i < q; i++) {
        u[i].first = nom[u[i].first];
        u[i].second = nom[u[i].second];
    }
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first;
            int id = g[x][i].second;
            if (blocked[id]) {
                e[nom[x]].pb(nom[y]);
            }
        }
    }
    memset(used, 0, sizeof(used));
    curt = 0;
    memset(tin, -1, sizeof(tin));
    memset(tout, -1, sizeof(tout));
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs2(i, -1);
        }
    }
    for (int i = 0; i < q; i++) {
        int z = lca(u[i].first, u[i].second);
        need0[u[i].first]++;
        need0[z]--;
        need1[u[i].second]++;
        need1[z]--;
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs3(i, -1);
    }
    puts("Yes");
}