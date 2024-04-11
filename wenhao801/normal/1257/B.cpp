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
        int x = read(), y = read();
        if (x == 1) { if (y == 1) puts("YES"); else puts("NO"); }
        else if (x == 2 || x == 3) {
            if (y >= 1 && y <= 3) puts("YES"); else puts("NO");
        }
        else puts("YES");
    }
    return 0;
}