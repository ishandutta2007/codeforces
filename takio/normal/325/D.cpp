#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define xx first
#define yy second
using namespace std;

const int N = 3010 * 3010 * 2;

int fa[N];
int n, m, q;
int dx[9] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[9] = {1, 0, -1, 0, 1, -1, 1, -1};
int id[3010][3010 * 2];
bool vis[3010][3010 * 2];
vector <pii> g;


int myfind (int x) {
    int f = x;
    while (fa[f] != f) f = fa[f];
    while (fa[x] != x) {
        int t = fa[x];
        g.push_back (pii (x, fa[x]));
        fa[x] = f;
        x = t;
    }
    return f;
}

int solve (int x, int y) {
    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (ty < 1) ty = 2 * m;
        if (ty > 2 * m) ty = 1;
        if (tx > n || tx < 1 || !vis[tx][ty]) continue;
//        cout << "x y " << tx << ' ' << ty << ' ' << myfind (id[tx][ty]) << endl;
        int u = myfind (id[x][y]), v = myfind (id[tx][ty]);
        if (u == v) continue;
        g.push_back (pii (v, fa[v]));
        fa[v] = u;
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int nn = 0;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * m; j++) {
            id[i][j] = ++nn;
            fa[nn] = nn;
        }
    }
    int res = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
//        cout << myfind (id[x][y]) << ' ' << myfind (id[x][y + m]) << endl;
        g.clear();
        vis[x][y] = 1;
        vis[x][y + m] = 1;
//        cout << x << ' ' << y << ' ' << myfind (id[x][y]) << ' ' << myfind (id[x][y + m]) << endl;
        solve (x, y);
        solve (x, y + m);
//        cout << x << ' ' << y << ' ' << myfind (id[x][y]) << ' ' << myfind (id[x][y + m]) << endl;
        if (myfind (id[x][y]) == myfind (id[x][y + m])) {
            for (int i = g.size() - 1; i >= 0; i--) {
                fa[g[i].xx] = g[i].yy;
            }
            vis[x][y] = 0;
            vis[x][y + m] = 0;
        } else {
            res++;
//            cout << x << ' ' << y << endl;
        }
    }
    cout << res << endl;
}