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

const int MAXN = 500500;
int n, a[MAXN], pand = 1023, por = 0, pxor = 0;
char s[MAXN][3];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) scanf("%s", s[i]), a[i] = read();
    for (i = 0; i < 10; i++) {
        int p0 = 0, p1 = 1;
        for (j = 1; j <= n; j++) {
            if (s[j][0] == '|') {
                p0 |= (a[j] >> i) & 1;
                p1 |= (a[j] >> i) & 1;
            }
            else if (s[j][0] == '&') {
                p0 &= (a[j] >> i) & 1;
                p1 &= (a[j] >> i) & 1;
            }
            else {
                p0 ^= (a[j] >> i) & 1;
                p1 ^= (a[j] >> i) & 1;
            }
        }
        if (p0 == p1) {
            if (!p0) pand -= 1 << i;
            else por += 1 << i;
        }
        else {
            if (p0) pxor += 1 << i;
        }
    }
    puts("3");
    printf("& %d\n| %d\n^ %d\n", pand, por, pxor);
    return 0;
}