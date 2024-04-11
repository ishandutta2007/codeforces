#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

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
        int a = read(), b = read(), ans = 1e9;
        for (int i = 0; i < 40000; i++) {
            if (b == 1 && i == 0) { continue; }
            int x = a, y = 0;
            while (x) x /= (b + i), ++y;
            ans = min(ans, i + y);
        }
        printf("%d\n", ans);
    }
    return 0;
}