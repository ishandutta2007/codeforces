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
int a, b, c, r;
int L, R;
int main () {
    int T = read();
    while (T--) {
        a = read(), b = read(), c = read(), r = read();
        if (a > b)swap(a, b);
        L = c - r, R = c + r;
        if (L > b || R < a) { cout << b - a << endl; continue; }
        if (L < a) L = a; if (R > b) R = b;
        printf("%d\n", (b - a) - (R - L));
    }
    return 0;
}