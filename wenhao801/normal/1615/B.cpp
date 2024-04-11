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

const int MAXN = 200200;
int s[MAXN][22];

int main () {
    for (int i = 1; i <= 200000; i++) for (int j = 0; j < 20; j++) s[i][j] = s[i - 1][j] + (1 & (i >> j));
    int T = read(); while (T--) {
        int l = read(), r = read(), ans = 0;
        for (int i = 0; i < 20; i++) ans = max(ans, s[r][i] - s[l - 1][i]);
        printf("%d\n", (r - l + 1) - ans);
    }
    return 0;
}