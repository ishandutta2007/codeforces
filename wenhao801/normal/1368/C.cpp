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

int main() {
    int n = read() + 1; printf("%d\n", n * 3 + 1);
    const int shift = 0;
    for (int i = 1; i <= n; i++) {
        const int sx = shift + i;
        #define out(x, y) printf("%d %d\n", sx + (x), sx + (y))
        if (i == 1) out(1, 1);
        out(1, 2), out(2, 1), out(2, 2);
    }
    return 0;
}