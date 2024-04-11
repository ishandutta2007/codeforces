#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 70, M = 260;
const LL INF = (1ll << 62) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, m, x, y, z;
int a[M], b[M], g[N][N], idx[N][N];
int l[3000][M], r[3000], ans[M];

inline int f(int x) { return x < -1 ? x + 3 : (x > 1 ? x - 3 : x); }

bool solve_eq(int n, int m, int a[][M], int b[]) {
    int p[M], c[M];
    rep(i, 1, m) p[i] = i;
    rep(k, 1, n) {
        bool flag = false;
        while (n >= k && !flag) {
            rep(j, k, m) if (a[k][j]) {
                rep(i, 1, n) swap(a[i][k], a[i][j]);
                swap(p[k], p[j]), flag = true;
                break;
            }
            if (!flag) {
                if (b[k])
                    return false;
                rep(j, k, m) swap(a[k][j], a[n][j]);
                swap(b[k], b[n]);
                n--;
            }
        }
        if (n < k)
            break;
        if (a[k][k] != 1) {
            rep(j, k, m) a[k][j] = f(-a[k][j]);
            b[k] = f(-b[k]);
        }
        rep(i, k + 1, n) if (a[i][k]) {
            int mul = a[i][k];
            rep(j, k, m) a[i][j] = f(a[i][j] - mul * a[k][j]);
            b[i] = f(b[i] - mul * b[k]);
        }
    }
    rep(k, 1, m) c[k] = b[k];
    rrep(k, n, 1) rep(i, 1, k - 1)
        c[i] = f(c[i] - a[i][k] * c[k]),
        a[i][k] = 0; // a[k][k] == 1

    rep(j, 1, m) b[p[j]] = c[j];
    return true;
}

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) rep(j, 1, n) g[i][j] = 0;
        rep(i, 1, m) scanf("%d%d%d", &x, &y, &z), g[x][y] = g[y][x] = z, idx[x][y] = idx[y][x] = i, a[i] = x, b[i] = y;

        int tot = 0;
        memset(l, 0, sizeof l), memset(r, 0, sizeof r);
        rep(i, 1, n) rep(j, i + 1, n) if (g[i][j]) {
            rep(k, j + 1, n) if (g[i][k] && g[j][k]) {
                tot++;
                g[i][j] < 0 ? (l[tot][idx[i][j]] = 1) : (r[tot] += 3 - g[i][j]);
                g[i][k] < 0 ? (l[tot][idx[i][k]] = 1) : (r[tot] += 3 - g[i][k]);
                g[j][k] < 0 ? (l[tot][idx[j][k]] = 1) : (r[tot] += 3 - g[j][k]);
                r[tot] = f(r[tot] % 3);
            }
        }

        bool flag = solve_eq(tot, m, l, r);
        if (!flag)
            printf("-1\n");
        else {
            rep(i, 1, m) {
                x = a[i], y = b[i];
                printf("%d ", g[x][y] >= 0 ? g[x][y] : (r[i] <= 0 ? 3 + r[i] : r[i]));
            }
            printf("\n");
        }
    }
    return 0;
}