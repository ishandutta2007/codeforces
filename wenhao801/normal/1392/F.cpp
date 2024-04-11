#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

using ll = long long;
inline ll read() {
    ll ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main() {
    int n = read(); ll s = 0;
    int i, j;
    for (i = 1; i <= n; i++) s += read();
    s -= 1ll * n * (n - 1) / 2;
    for (i = 1; i <= n; i++) printf("%lld ", i - 1 + s / n + bool(s % n >= i));
    putchar('\n');
    return 0;
}