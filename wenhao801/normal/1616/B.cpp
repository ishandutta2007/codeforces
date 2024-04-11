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

const int MAXN = 100100;
int n; char a[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        scanf("%s", a + 1);
        if (n == 1 || a[1] <= a[2]) { putchar(a[1]), putchar(a[1]), putchar('\n'); continue; }
        for (i = 2; i <= n; i++) if (a[i - 1] < a[i]) break;
        --i; for (j = 1; j <= i; j++) putchar(a[j]); for (j = i; j >= 1; j--) putchar(a[j]); puts("");
    }
    return 0;
}