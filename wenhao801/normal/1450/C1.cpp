#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 303;
char a[MAXN][MAXN]; int n;
void op(int x, char c) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if ((i + j) % 3 == x && a[i][j] != '.') a[i][j] = c;
}

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j;
        int b[3][2] = {};
        for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
        for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (a[i][j] != '.')
            b[(i + j) % 3][a[i][j] == 'X']++;
        int mx = max({b[0][0] + b[0][1], b[1][0] + b[1][1], b[2][0] + b[2][1]});
        for (i = 0; i < 3; i++) if (b[i][0] + b[i][1] == mx) {
            int u = i ? 0 : 1, v = 3 - i - u;
            if (b[u][0] + b[v][1] < b[v][0] + b[u][1]) op(u, 'X'), op(v, 'O');
            else op(u, 'O'), op(v, 'X');
            break;
        }
        for (i = 1; i <= n; i++) puts(a[i] + 1);
    }
    return 0;
}