#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;

const int N = 5e5;
const int INF = 1e9 + 19;

vector< pair<int, pair<int, int> > > g[N];
int ok[N], val[N], n, m, was[N], root, xx, yy, used[N];
vector<int> uu[N], vv[N];

void dfs(int x) {
//  cerr << x << " " << endl;
    for (int i = 0; i < (int)g[x].size(); i++) {
        int y = g[x][i].fr;
        int u = g[x][i].sc.fr;
        int v = g[x][i].sc.sc;
//      cerr << x << " " << y << endl;
        if (val[u] != -1) continue;
//      db2(u, val[u]);
//      cerr << ok[y] << endl;
        if (!ok[y]) {
            val[u] = v;
            ok[y] = 1;
            dfs(y);
        }
    }
}

void dfs2(int x, int px) {
    was[x] = 1;
    for (int i = 0; i < (int)g[x].size(); i++) {
        int y = g[x][i].fr;
        assert(!ok[y]);
        if (g[x][i].sc.fr == px) continue;
        if (!was[y]) {
            dfs2(y, g[x][i].sc.fr);
        } else {
            root = y;
            xx = g[x][i].sc.fr;
            yy = g[x][i].sc.sc;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++) {
            int x;
            scanf("%d", &x);
            if (x < 0) {
                uu[abs(x) - 1].pb(i);
            } else {
                vv[abs(x) - 1].pb(i);
            }
        }
    }
    for (int i = 0; i < m; i++) val[i] = -1;
    for (int i = 0; i < m; i++) {
        if (uu[i].empty()) {
            val[i] = 1;
            for (int j = 0; j < (int)vv[i].size(); j++) {
                ok[vv[i][j]] = 1;
            }
        } else if (vv[i].empty()) {
            val[i] = 0;
            for (int j = 0; j < (int)uu[i].size(); j++) {
                ok[uu[i][j]] = 1;
            }
        } else {
            int x = uu[i][0];
            int y = vv[i][0];
            g[x].pb(mp(y, mp(i, 1)));
            g[y].pb(mp(x, mp(i, 0)));
        }
    }
    for (int i = 0; i < n; i++) {
        if (ok[i]) dfs(i);
    }
    for (int i = 0; i < n; i++) {
        if ((!ok[i]) && (!was[i])) {
            root = -1;
            dfs2(i, -1);
//          cerr << root << endl;
            if (root == -1) {
                puts("NO");
                return 0;
            } else {
                val[xx] = yy;
                ok[root] = 1;
                used[xx] = 1;
                dfs(root);
            }
        }
    }
//  cerr << val[2] << endl;
//  exit(0);
    puts("YES");
    for (int i = 0; i < m; i++) {
        if (val[i]  < 0) val[i] = 0;
        putchar(val[i] + '0');  
//      cerr << val[i] << endl;

    }
    puts("");
}