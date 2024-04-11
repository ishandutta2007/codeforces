#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int mp[N][N], d[N][N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
        mp[u][v] = mp[v][u] = 1;
    }
    if (mp[1][n] == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] ^= 1;
            }
        }
    }
    memset (d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j]) d[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[j][k] = min (d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    printf ("%d\n", d[1][n] == INF ? -1 : d[1][n]);
}