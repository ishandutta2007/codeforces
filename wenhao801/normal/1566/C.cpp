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

const int inf = 1e9 + 7;
char a[3][100100];
int f[100100][4];
int main () {
    int T = read();
    while (T--) {
        int n = read(); scanf("%s", a[1] + 1); scanf("%s", a[2] + 1);
        int i, j; f[0][2] = 0, f[0][0] = -1e9, f[0][1] = -1e9;
        for (i = 1; i <= n; i++) {
            if (a[1][i] != a[2][i]) { f[i][0] = f[i][1] = -1e9; f[i][2] = max(f[i - 1][2] + 2, max(f[i - 1][0] + 3, f[i - 1][1] + 2)); }
            else {
                if (a[1][i] == '0') {
                    f[i][0] = max(1 + f[i - 1][0], f[i - 1][2]);
                    f[i][1] = -1e9;
                    f[i][2] = max(2 + f[i - 1][1], f[i - 1][2] + 1);
                }
                else {
                    f[i][0] = -1e9;
                    f[i][1] = max(f[i - 1][1], f[i - 1][2]);
                    f[i][2] = max(2 + f[i - 1][0], f[i - 1][2]);
                }
            }
        } i = n;
        printf("%d\n", max(f[i][0] + 1, max(f[i][1], f[i][2])));
    }
    return 0;
}