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

const int MAXN = 100100;
int n, a[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j, L = 1;
        for (i = 1; i <= n; i++) a[i] = read();
        while (L <= n && !a[L]) ++L;
        for (int r = n - 1; r >= 1; r--) {
            L = max(L - 1, 1);
            for (i = L; i <= r; i++) a[i] = a[i + 1] - a[i];
            sort(a + L, a + r + 1); while (L <= n && !a[L]) ++L;
            if (!a[r]) break;
        }
        printf("%d\n", a[1]);
    }
    return 0;
}