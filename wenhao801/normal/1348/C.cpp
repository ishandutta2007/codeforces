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

char a[100100] = {};

int main () {
    int T = read();
    while (T--) {
        int n = read(), k = read(), i;
        scanf("%s", a + 1);
        sort(a + 1, a + n + 1);
        if (a[1] != a[k]) putchar(a[k]);
        else {
            putchar(a[1]);
            if (a[k + 1] == a[n]) {
                int t = ((n - k) % k) ? ((n - k) / k + 1) : ((n - k) / k);
                while (t--) putchar(a[k + 1]);
            }
            else for (i = k + 1; i <= n; i++) putchar(a[i]);
        }
        puts("");
    }
    return 0;
}