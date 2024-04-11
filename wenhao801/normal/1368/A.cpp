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
    int T = read(); while (T--) {
        int a = read(), b = read(), n = read();
        if (a > b) swap(a, b);
        int cnt = 0;
        while (b <= n) a += b, swap(a, b), ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}