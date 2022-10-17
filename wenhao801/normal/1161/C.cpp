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

int buc[55];

int main () {
    int n = read(), i;
    for (i = 1; i <= n; i++) ++buc[read()];
    for (i = 1; i <= 50; i++) if (buc[i]) {
        if (buc[i] > (n >> 1)) { puts("Bob"); } else puts("Alice"); return 0;
     }
    return 0;
}