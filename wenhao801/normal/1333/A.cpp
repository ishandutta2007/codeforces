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

int main () {
    int T = read();
    while (T--) {
        int n = read(), m = read();
        int i, j;
        putchar('W');
        for (i = 2; i <= m; i++) putchar('B'); puts("");
        for (i = 2; i <= n; i++) {for (j = 1; j <= m; j++) putchar('B'); puts("");}
    }
    return 0;
}