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

const int C = 720720;
int main () {
    int n = read(), m = read();
    int i, j;
    for (i = 1; i <= n; i++) {for (j = 1; j <= m; j++) {
        int x = read();
        if ((i + j) & 1) printf("%d ", C);
        else printf("%d ", C + x * x * x * x);
    } puts(""); }
    return 0;
}