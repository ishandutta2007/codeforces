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

inline int ask (int x) { printf("? %d\n", x); fflush(stdout); return read(); }

int main () {
    int n = read(), i, j;
    int L = n, R = 4004000, res = -1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (ask(mid) == 1) res = mid, R = mid - 1;
        else L = mid + 1;
    }
    int ans = res;
    for (i = 2; i <= n; i++) {
        int w = (res - i + 1) / i + bool((res - i + 1) % i);
        int tmp = ask(w);
        if (tmp) ans = min(ans, w * tmp);
    }
    printf("! %d\n", ans);
    return 0;
}