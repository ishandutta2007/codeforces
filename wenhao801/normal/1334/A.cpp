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
        int n = read();
        int la = 0, lb = 0;
        bool f = true;
        while (n--) {
            int x = read(), y = read();
            if (x >= la && y >= lb && x - la >= y - lb) {la = x, lb = y; continue; }
            f = false;
        }
        if (f) puts("YES"); else puts("NO");
    }
    return 0;
}