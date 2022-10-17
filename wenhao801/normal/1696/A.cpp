#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read(); while (T--) {
        int n = read(), z = read(), mx = 0;
        while (n--) mx = max(mx, read() | z);
        printf("%d\n", mx);
    }
    return 0;
}