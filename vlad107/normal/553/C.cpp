#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

const int N = 1e5 + 100;
const int BASE = 1e9 + 7;

int n, m, t[N], ans;
vector< pair<int,int> > g[N];

void dfs(int x) {
    // cerr << x << " " << t[x] << endl;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i].first;
        int z = g[x][i].second ^ t[x];
        // cerr << z << endl;
        if (t[y] < 0) {
            t[y] = z;
            dfs(y);
        } 
        if (t[y] != z) ans = 0;
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= BASE) x -= BASE;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x; --y;
        z^=1;
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
    }
    memset(t, -1, sizeof(t));
    ans = (BASE + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (t[i] < 0) {
            add(ans, ans);
            t[i] = 0;
            dfs(i);
        }
    }
    printf("%d\n", ans);
}