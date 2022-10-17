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

int main() {
    int n = read(), m = read();
    if (n == 1 && m == 1) { puts("0"); return 0; }
    if (n == 1) { for (int i = 1; i <= m; i++) printf("%d ", i + 1); putchar('\n'); return 0; }
    if (m == 1) { for (int i = 1; i <= n; i++) printf("%d\n", i + 1); return 0; }
    for (int i = 1; i <= n; i++, cout << endl) for (int j = 1; j <= m; j++) printf("%d ", i * (n + j));
    return 0;
}