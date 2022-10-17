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

const int MAXN = 1001000;
char a[MAXN], b[MAXN]; int n;

int main() {
    n = read(); scanf("%s", a + 1), scanf("%s", b + 1);
    int i, j, ans = 0;
    for (i = 1; i <= n; i++) {
        if (i < n && a[i] == b[i + 1] && a[i + 1] == b[i] && a[i] != a[i + 1]) { ++ans, ++i; }
        else ans += a[i] != b[i];
    }
    printf("%d\n", ans);
    return 0;
}