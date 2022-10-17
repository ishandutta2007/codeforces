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
        int n = read(); long long ans = 0;
        int last = 0;
        for (int i = 1; i <= n; i++) {
            int x = read();
            if (i == 1) last = x;
            else ans += max(0, last - x), last = x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}