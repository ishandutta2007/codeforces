#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

const int N = 25;
char row[N], col[N];

const int INF = 1000000000;

int f[N * N][N * N];

inline int cal(int x, int y) {
    return x * m + y;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", row, col);
    int l = n * m; 
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            f[i][j] = INF;
        }
        f[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (col[j] == '^') {
                if (i) {
                    f[cal(i, j)][cal(i - 1, j)] = 1;
                }
            } else {
                if (i + 1 < n) {
                    f[cal(i, j)][cal(i + 1, j)] = 1;
                }
            }
            if (row[i] == '<') {
                if (j) {
                    f[cal(i, j)][cal(i, j  - 1)] = 1;
                }
            } else {
                if (j + 1 < m) {
                    f[cal(i, j)][cal(i, j + 1)] = 1;
                }
            }
        }
    }
    for (int k = 0; k < l; ++k) {
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            if (f[i][j] == INF) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}