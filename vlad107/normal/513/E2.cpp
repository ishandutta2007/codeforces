#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int coef[5] = {-1, +1};
const int N = 30300;
const int K = 250;

int n, k, a[N];
int f[N][K][2][2][2];

void upd(int &x, int y) {
    if (y > x) x = y;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 2; z++) f[i][j][x][y][z] = -INF;
                }
            }
        }
    }
    f[0][0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 2; z++) {
                        if (f[i][j][x][y][z] == -INF) continue;
                        if (x == 1) {
                            int cur = f[i][j][x][y][z];
                            if (j != 1) cur += coef[y] * a[i];
                            if (j != k) cur += coef[z] * a[i];
                            upd(f[i + 1][j][1][y][z], cur);
                        }
                        upd(f[i + 1][j][0][y][z], f[i][j][x][y][z]);
                        if (j + 1 <= k) {
                            int ny = 1 - z;
                            for (int nz = 0; nz < 2; nz++) {
                                int cur = f[i][j][x][y][z];
                                if (j != 0) cur += coef[ny] * a[i];
                                if (j + 1 != k) cur += coef[nz] * a[i];
//                              cerr << cur << endl;
                                upd(f[i + 1][j + 1][1][ny][nz], cur);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -INF;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
                ans = max(ans, f[n][k][x][y][z]);
            }
        }
    }
    printf("%d\n", ans);
}