#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 505;

int n, m;

char map[N][N];

int sum1[N][N], sum2[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (map[i][j] == '.' && map[i][j + 1] == '.') {
                ++sum1[i + 1][j + 1];
            }
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && map[i + 1][j] == '.') {
                ++sum2[i + 1][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum1[i][j] += sum1[i][j - 1] + sum1[i - 1][j] - sum1[i - 1][j - 1];
            sum2[i][j] += sum2[i][j - 1] + sum2[i - 1][j] - sum2[i - 1][j - 1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x0, y0, x1, y1;
        scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
        int ans = 0;
        --x0, --y0;
        ans += sum1[x1][y1 - 1] - sum1[x1][y0] - sum1[x0][y1 - 1] + sum1[x0][y0];
        ans += sum2[x1 - 1][y1] - sum2[x1 - 1][y0] - sum2[x0][y1] + sum2[x0][y0];
        printf("%d\n", ans);
    }
    return 0;
}