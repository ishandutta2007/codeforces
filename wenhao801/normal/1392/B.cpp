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

int n; long long k;
int a[202000];
void next() {
    int mx = *max_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i] = mx - a[i];
}

int main() {
    int T = read(); while (T--) {
        n = read(); cin >> k; int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        --k; next();
        if (k & 1) next();
        for (int i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
    }
    return 0;
}