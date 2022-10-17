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
        int n = read();
        if (n == 1) puts("-1");
        else {
            for (int i = 3; i <= n; i++) putchar('3');
            putchar('5'); putchar('3'); putchar('\n');
        }
    }
    return 0;
}