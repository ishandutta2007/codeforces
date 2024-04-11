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

int n, x, a[110];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        if (n & 1) puts("NO");
        else {
            n >>= 1; int x = sqrt(n);
            if (x * x  == n) puts("YES"); else {
                if (n & 1) puts("NO");
                else {
                    n >>= 1; x = sqrt(n);
                    if (x * x == n) puts("YES"); else puts("NO");
                }
            }
        }
    }
    return 0;
}