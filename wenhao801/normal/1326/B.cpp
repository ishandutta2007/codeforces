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

const int MAXN = 200200;
int n; long long b[MAXN], a[MAXN], x[MAXN];

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) b[i] = read();
    for (i = 1; i <= n; i++) {
        a[i] = b[i] + x[i];
        x[i + 1] = max(x[i], a[i]);
        printf("%lld ", a[i]);
    }
    putchar('\n');
    return 0;
}