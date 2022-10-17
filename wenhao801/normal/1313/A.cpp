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
        int a = read(), b = read(), c = read();
        if (a < b) swap(a, b); if (a < c) swap(a, c); if (b < c) swap(b, c);
        int ans = 0;
        if (a) ans++, a--; if (b) ans++, b--; if (c) ans++, c--;
        if (a && b) ans++, a--, b--; if (a && c) ans++, a--, c--; if (b && c) ans++, b--, c--;
        if (a && b && c) ans++;
        printf("%d\n", ans);
    }
    return 0;
}