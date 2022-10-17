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
    int n = read();
    int i, j = 0;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            if (!j) j = i;
            else if (n / j == i) continue;
            else return 0;
        }
    }
    printf("%d%d\n", j, n / j);
    return 0;
}