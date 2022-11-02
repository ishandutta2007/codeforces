#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
//#define piii pair <int, pii>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;

const int INF =  2e9, N = 1010;
int a[N][N], vis[N][N], fa[N * N], sz[N * N], b[N][N];
int n, m;
LL k;
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
vector <piii> g;

int getfa (int x) { if (!fa[x]) return x; return fa[x] = getfa (fa[x]); }

void add (int a, int b, int c, int d) {
    vis[a][b] = 1;
    if (!vis[c][d]) return;
    int e = (a - 1) * m + b;
    int f = (c - 1) * m + d;
    e = getfa (e);
    f = getfa (f);
    if (e == f) return;
//    cout << "add " << e << ' ' << f << endl;
    fa[e] = f;
    sz[f] += sz[e];
}

int solve (int l, int r) {
//    cout << l << ' ' << r << endl;
    int v = g[l].xx;
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < 4; j++) {
            int x = g[i].yy.xx + dx[j];
            int y = g[i].yy.yy + dy[j];
            add (g[i].yy.xx, g[i].yy.yy, x, y);
        }
    }
//    cout << v << endl;
    if (k % v == 0) {
        for (int i = l; i <= r; i++) {
            int tx = g[i].yy.xx;
            int ty = g[i].yy.yy;
            int id = (tx - 1) * m + ty;
            id = getfa (id);
//            cout << sz[id] << endl;
            if (sz[id] >= k / v) {
                queue <pii> q;
                cout << "YES\n";
                memset (vis, 0, sizeof vis);
                vis[tx][ty] = 1;
                q.push (pii (tx, ty));
                k /= v;
                while (!q.empty () && k--) {
                    pii u = q.front();
                    b[u.xx][u.yy] = v;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int x = u.xx + dx[i];
                        int y = u.yy + dy[i];
                        if (a[x][y] < v || vis[x][y]) continue;
                        vis[x][y] = 1;
                        q.push (pii (x, y));
                    }
                }
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) printf ("%d ", b[i][j]);
                    printf ("\n");
                }
                return 1;
            }
        }
    }
    return 0;
}

bool cmp (piii x, piii y) {
    return x.xx > y.xx;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf ("%d", &a[i][j]);
            sz[(i - 1) * m + j] = 1;
            g.push_back (piii (a[i][j], pii (i, j)));
        }
    }
    sort (g.begin(), g.end(), cmp);
    for (int i = 0; i < n * m; ) {
        int j = i + 1;
        if (j < n * m && g[j].xx == g[i].xx) j++;
        if (solve (i, j - 1)) { return 0; }
        i = j;
    }
    cout << "NO";
}