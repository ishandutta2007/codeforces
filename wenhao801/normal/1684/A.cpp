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

int main () {
    int T = read(); while (T--) {
        int n = read();
        if (n >= 10 && n <= 99) printf("%d\n", n % 10);
        else {
            int mn = 9;
            while (n) mn = min(mn, n % 10), n /= 10;
            printf("%d\n", mn);
        }
    }
    return 0;
}