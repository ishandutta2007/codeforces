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

int n, a[55];

int main () {
    n= read(); int i, j;
    for (i = 1; i <= n; i++ )a[i] = read();
    sort(a + 1, a + n + 1); n = unique(a + 1, a + n + 1) - a - 1;
    for (i = 1; i <= n - 2; i++) if (a[i] == a[i+ 1] - 1 && a[i + 2] == a[i + 1] + 1) {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}