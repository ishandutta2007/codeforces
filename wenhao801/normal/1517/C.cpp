#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, b[505], a[505][505];

int main () {
    n = read(); int i, j, k;
    for (i = 1; i <= n; i++) b[i] = read();
    for (i = 1; i <= n; i++) {
        a[i][i] = b[i];
        int x = i, y = i, o = b[i];
        while (--b[i]) {
            if (y != 1 && !a[x][y - 1]) --y;
            else if (x != n && !a[x + 1][y]) ++x;
            else { puts("-1"); return 0; }
            a[x][y] = o;
        }
    }
    for (i = 1; i <= n; i++) { for (j = 1; j <= i; j++) cout << a[i][j] << ' '; cout << endl; }
    return 0;
}