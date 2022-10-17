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

char a[50050];

int main() {
    int T = read(); while (T--) {
        scanf("%s", a + 1); int n = strlen(a + 1);
        int s = 0, c = 0, d = 0;
        for (int i = 1; i <= n; i++) s += a[i] - '0', c += a[i] == '0', d += (a[i] - '0') % 2 == 0;
        if (s % 3 == 0 && c && d - 1) puts("red"); else puts("cyan");
    }
    return 0;
}