#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int N = 505;

struct dat {
    int l, r, u, d;
} d[N][N];
int n, m, k, x, y;
int f[500], g[500], ans[N][N];

inline int encode(int x, int y) { return (x + 10) * 21 + (y + 10); }

int main() {
    cin >> n >> m >> k;
    if (k % 2) {
        rep(i, 1, n) rep(j, 1, m) printf("-1%c", j < m ? ' ' : '\n');
        return 0;
    }

    k /= 2;
    rep(i, 1, n) rep(j, 1, m - 1) scanf("%d", &x), d[i][j].r = d[i][j + 1].l = x;
    rep(i, 1, n - 1) rep(j, 1, m) scanf("%d", &x), d[i][j].d = d[i + 1][j].u = x;

    rep(i, 1, n) rep(j, 1, m) {
        f[encode(0, 0)] = 0;
        rep(k1, 1, k) {
            rep(x, -k1, k1) rep(y, -k1 + abs(x), k1 - abs(x)) g[encode(x, y)] = INF;

            rep(x, -k1 + 1, k1 - 1) rep(y, -k1 + 1 + abs(x), k1 - 1 - abs(x)) {
                int key = encode(x, y);
                if (f[key] < INF) {
                    int gx = i + x, gy = j + y;
                    if (gx > 1) {
                        int key1 = encode(x - 1, y);
                        g[key1] = min(g[key1], f[key] + d[gx][gy].u);
                    }
                    if (gx < n) {
                        int key1 = encode(x + 1, y);
                        g[key1] = min(g[key1], f[key] + d[gx][gy].d);
                    }
                    if (gy > 1) {
                        int key1 = encode(x, y - 1);
                        g[key1] = min(g[key1], f[key] + d[gx][gy].l);
                    }
                    if (gy < m) {
                        int key1 = encode(x, y + 1);
                        g[key1] = min(g[key1], f[key] + d[gx][gy].r);
                    }
                }
            }
            swap(f, g);
            //cerr << i << " " << j << " " << k1 << " " << f[encode(0, 0)] << endl;
        }
        int tmp = INF;
        rep(x, -k, k) rep(y, -k + abs(x), k - abs(x)) tmp = min(tmp, f[encode(x, y)] << 1);
        ans[i][j] = tmp;
    }

    rep(i, 1, n) rep(j, 1, m) printf("%d%c", ans[i][j], j < m ? ' ' : '\n');
    return 0;
}