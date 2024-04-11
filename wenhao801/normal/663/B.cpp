#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
char a[202]; int len;

int main () {
    int T = read(); while (T--) {
        scanf("%s", a + 1); len = strlen(a + 1); int i, j;
        ll now = 1988, s = 0, cur = 10;
        for (i = len; i >= 5; i--, cur *= 10) {
            s += cur / 10 * (a[i] - '0');
            if (s <= now % cur) now += cur;
            now = now / cur * cur + s;
        }
        printf("%lld\n", now);
    }
    return 0;
}