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
        int b = read(), p = read(), f = read();
        int h = read(), c = read();
        int ans = 0;
        if (h > c) {
            int t = min(b / 2, p);
            ans += t * h;
            b -= t * 2, p -= t;
            if (b >= 2) {
                t = min(b / 2, f);
                ans += t * c;
            }
            printf("%d\n", ans);
        }
        else {
            int t = min(b / 2, f);
            ans += t * c;
            b -= t * 2, f -= t;
            if (b >= 2) {
                t = min(b / 2, p);
                ans += t * h;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}