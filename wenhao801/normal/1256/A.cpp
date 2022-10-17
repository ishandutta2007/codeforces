#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

signed main () {
    int Q = read();
    while (Q--) {
        int a = read(), b = read(), n = read(), s = read();
        if (s <= a * n) {
            s %= n;
            if (s <= b) puts("YES");
            else puts("NO");
        }
        else {
            s -= a * n;
            if (s <= b) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}