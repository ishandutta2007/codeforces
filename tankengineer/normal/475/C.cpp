#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

const int N = 1005;
char map[N][N];

int sum[N][N];

int getsum(int x0, int y0, int x1, int y1) {
    return sum[x1 + 1][y1 + 1] - sum[x1 + 1][y0] - sum[x0][y1 + 1] + sum[x0][y0];
}

bool check(int a, int b, int x0, int y0) {
    while (true) {
        if (x0 + a > n || y0 + b > m) {
            return false;
        }
        if (getsum(x0, y0, x0 + a - 1, y0 + b - 1) != a * b) {
            return false;
        }
        if ((y0 + b == m || getsum(x0, y0 + b, n - 1, m - 1) == 0) &&
            (x0 + a == n || getsum(x0 + a, y0, n - 1, m - 1) == 0)) {
            break;
        }
        if (y0 + b < m && map[x0][y0 + b] == 'X') {
            if (x0 + a < n && getsum(x0 + a, y0, n - 1, y0) != 0) {
                return false;
            }
            ++y0;
            continue;
        }
        if (x0 + a < n && map[x0 + a][y0] == 'X') {
            if (y0 + b < m && getsum(x0, y0 + b, x0, m - 1) != 0) {
                return false;
            }
            ++x0;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    int sx = n, sy = m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'X') {
                sx = min(sx, i), sy = min(sy, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (map[i][j] == 'X');
        }
    }
    if (map[sx][sy] != 'X') {
        puts("-1");
        return 0;
    }
    int ans = n * m + 1;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= m; ++b) {
            if (a * b < ans) {
                if (check(a, b, sx, sy)) {
                    ans = a * b;
                }
            }
        }
    }
    if (ans > n * m) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}